## Подготовка:

Для сборки необходимы заголовочники OpenSSL

```
apt-get install libssl-dev
```

## Сборка:   
```
mkdir build
cd build
cmake ..
make
```

## Запуск:
```
CERT_PATH="<path-to-cert>" ./cloud-installer
```

