# ugrid-gui

Qt GUI for [Ultragrid](https://github.com/CESNET/UltraGrid)

![GUI](https://i.imgur.com/hNlzPy4.png)

## Compilation

```
qmake .
make
```

## Usage

When the ultragrid binary is in the system PATH variable the GUI detects it and launches.
```
./ugrid-gui
```
Otherwise the binary path can be specified manually:
```
./ugrid-gui --with-uv ~/ultragrid/bin/uv
```
