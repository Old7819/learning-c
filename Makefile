# Компилятор и флаги
CC = gcc
CFLAGS = -Wall -Wextra -g -std=c11
LDFLAGS = -lm

# Директории
SRCDIR = src
BUILDDIR = build

# Автоматический поиск всех .c файлов
SOURCES = $(wildcard $(SRCDIR)/*.c)
TARGETS = $(patsubst $(SRCDIR)/%.c, $(BUILDDIR)/%, $(SOURCES))

# Основная цель
all: $(BUILDDIR) $(TARGETS)

# Правило сборки
$(BUILDDIR)/%: $(SRCDIR)/%.c | $(BUILDDIR)
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

# Создание папки build
$(BUILDDIR):
	mkdir -p $(BUILDDIR)

# Очистка
clean:
	rm -f $(TARGETS)
	@echo "✅ Build files cleaned safely."

.PHONY: all clean