# Wymagania
## SDL3
**Instalacja**:\
`sudo apt install sdl3-devel`
## [Pigpio](https://github.com/joan2937/pigpio)
**Instalacja**\
Zainstaluj zależności:
``sudo apt install python3-setuptools``

Pobierz i skompiluj:
```
git clone https://github.com/joan2937/pigpio
cd pigpio
make
sudo make install
```

# Kompilacja
```
mkdir build
cd build
cmake ..
```
# Uruchamianie
Program musi być uruchomiony jako root (sudo) ponieważ wymaga dostępu do gpio\
`sudo ./lazik`

Aby program uruchamiał się po starcie systemu można skonfigurować usługę systemd. W tym celu należy umieścić plik `lazik.service` w `/etc/systemd/system` i zmienić ścieżkę w polu ExecStart na lokalizację programu

# Piny
W pliku main.cpp tworzone są obiekty `motor_l` i `motor_r` zdefiniowane są tam piny:
- `en_a` i `en_b` - używane do kierunku silnika
- `pwm` - regulacja prędkości
- `en` - włącza lub wyłącza sterownik silnika, było używane z poprzednim sterownikiem, aktualnie niewykorzystane

