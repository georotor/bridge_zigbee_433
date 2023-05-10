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

