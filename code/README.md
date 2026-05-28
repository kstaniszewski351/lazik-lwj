# Wymagania
## SDL3
**Instalacja**:\
`sudo apt install libsdl3-dev`
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



# Przygotowanie środowiska do edycji i testowania
**Instalacja rozszerzeń**\
Potrzebna rozszerzenia do VSCode:
- [Remote-SSH](https://marketplace.visualstudio.com/items?itemName=ms-vscode-remote.remote-ssh)
- [CMake Tools](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cmake-tools)
- [C/C++](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools)

Na komputerze potrzebny jest równierz klient SSH

Aby połączyć się z Raspberry Pi należy użyć komendy `Connect to Host` po wciśnięciu `ctrl+shift+p`. Następnie serwer rozszerzenia zostanie automatycznie zainstalowany. Po instalacji należy zainstalować potrzebne rozszerzenia równierz na Raspberry Pi. Program można wtedy kompilować i uruchamiać zdalnie na Raspberry Pi za pomocą rozszerzenia Cmake Tools.

# Piny
W pliku main.cpp tworzone są obiekty `motor_l` i `motor_r` zdefiniowane są tam piny:
- `en_a` i `en_b` - używane do kierunku silnika
- `pwm` - regulacja prędkości
- `en` - włącza lub wyłącza sterownik silnika, było używane z poprzednim sterownikiem, aktualnie niewykorzystane

