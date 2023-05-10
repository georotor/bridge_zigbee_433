# Мост Zigbee 433

Мост для использования простых выключателей и брелков на 433 МГц с датчиком температуры.



**Компоненты:**

- CC2530 - Zigbee модуль
- Wemos D1 mini - Модуль с esp8266
- E07-M1101D - Приемник 433 МГц с чипом CC1101
- AM2302 - Датчик температуры и влажности



## Zigbee модуль CC2530

В качестве прошивки используется PTVO (https://ptvo.info/). 

### Конфигурация выходов в прошивке

Готовая прошивка лежит в каталоге ptvo, сконфигурирована:

- P15 - DHT 22
- P02 - UART, скорость 9600, окончание пакета 0x0D
- P03 - UART, скорость 9600, окончание пакета 0x0D

### Прошивка

Для заливки прошивки использовался SmartRF04EB.

#### Подключение

![Подключение](https://github.com/georotor/bridge_zigbee_433/blob/main/ptvo/smartrf04eb-pinout.png?raw=true)

| SmartRF04EB | CC2530 |
| :---------: | :----: |
|      1      |  GND   |
|      3      |  P22   |
|      4      |  P21   |
|      7      |  RST   |
|      9      |  VCC   |

#### CC-Tool

Для заливки используется cc-tool (https://github.com/dashesy/cc-tool).

macOS:

```shell
brew install autoconf automake libusb boost pkgconfig libtool

git clone https://github.com/dashesy/cc-tool.git
cd cc-tool

CPPFLAGS="-I/opt/homebrew/include" \
LDFLAGS="-I/opt/homebrew/include" \
 ./bootstrap

CPPFLAGS="-I/opt/homebrew/include" \
CXXFLAGS="-std=c++0x" \
LDFLAGS="-L/opt/homebrew/lib" \
LIBUSB_CFLAGS="-I/opt/homebrew/include" \
 ./configure

make

sudo make install

sudo cc-tool -e -w ptvo/ptvo-dht22-uart.hex
```

### Подключение

| CC2530 | Wemos D1 mini | AM2302 |
| :----: | :-----------: | :----: |
|  P15   |               |  Out   |
|  P02   |      TX       |        |
|  P03   |      RX       |        |

Питание (3.3V) и земля по месту.



## Wemos D1 mini

Модуль используется в качестве моста между CC1101 и CC2530.

### Прошивка

В прошивке (wemos/cc1101.ino) реализован простейший прием данных с CC1101 и отправка их в UART для CC2530.

### Подключение

| Wemos D1 mini | E07-M1101D (CC1101) | CC2530 |
| :-----------: | :-----------------: | :----: |
|      D1       |        GDO0         |        |
|      D2       |        GDO2         |        |
|      D5       |         SCK         |        |
|      D6       |        MISO         |        |
|      D7       |        MOSI         |        |
|      D8       |         CSN         |        |
|      RX       |                     |  P03   |
|      TX       |                     |  P02   |

Питание (3.3V) и земля по месту.
