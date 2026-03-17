# Используем образ Ubuntu
FROM ubuntu:latest

# Устанавливаем необходимые зависимости (если есть)
RUN apt-get update && apt-get install -y \
    libc6 \
    && rm -rf /var/lib/apt/lists/*

# Устанавливаем рабочую директорию
WORKDIR /app

# Копируем скомпилированный бинарный файл в контейнер
COPY main .

# Указываем команду для запуска
CMD ["./main"]
