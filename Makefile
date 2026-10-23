# Змінні (Макроси)
# Компiлятор C
CC = gcc

# Прапорці компіляції:
# -IHeader : додати директорію Header до шляхів пошуку заголовочних файлів
# -Wall    : увімкнути всі основні попередження
CFLAGS = -IHeader -Wall

# -lm : підключити математичну бібліотеку (libm)
LDFLAGS = -lm

# Назва підсумкового виконуваного файлу
TARGET = lab5

# Список об'єктних файлів, необхідних для збірки
OBJS = main.o funcs.o

# Правила збірки
# Головна ціль за замовчуванням
all: $(TARGET)

# Правило для компонування підсумкового виконуваного файлу з об'єктних файлів
$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET) $(LDFLAGS)

# Компіляція main.c в main.o
main.o: Source/main.c Header/funcs.h
	$(CC) $(CFLAGS) -c Source/main.c -o main.o

# Компіляція funcs.c в funcs.o
funcs.o: Source/funcs.c Header/funcs.h
	$(CC) $(CFLAGS) -c Source/funcs.c -o funcs.o

# Очищення
clean:
	rm -f *.o $(TARGET) main.exe Source/main.exe