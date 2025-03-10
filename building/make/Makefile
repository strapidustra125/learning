# ------------------------------------------------------------------------------------------------ #
# Настройка переменных окружения

# Компилятор
CXX			= g++

# Опция дебага (-g)
DEBUG   	= -g

# Флаги для компилятора
CXXFLAGS	= -Wall $(DEBUG) -std=c++17

# Линкуемые библиотеки
LDLIBS		= -pthread

# Включает в переменные все файлы с расширениями .cpp и .h соответственно из текущей директории
SOURCES		= $(wildcard *.cpp)
INCLUDES	= $(wildcard *.h)

# Берет все содержимое переменной SOURCES и заменяет .cpp на .o
OBJECTS		= $(SOURCES:.cpp=.o)

# Имя целевого исполняемого файла
EXECUTABLE	= application


# ------------------------------------------------------------------------------------------------ #
# Описание целей


# Основная цель для сборки: стоит первой, поэтому вызывается по-умолчанию командной "make"
# В зависимостях:
#	clean         - очистит уже существующие объектные файлы и бинарник
#	$(SOURCES)    - .cpp исходники проекта
#	$(EXECUTABLE) - сборка объектных файлов для исходников
all: clean $(SOURCES) $(EXECUTABLE)
	@echo "-- Building target: \"all\""

# Вспомогательная цель для очистки директории проекта
clean:
	@echo "-- Cleaning work directory from all executable and .o files"
	@echo "-- Removing executable : $(EXECUTABLE)"
	@echo "-- Removing objects    : $(wildcard *.o)"
	@echo "-- Running command :"
	rm -f $(EXECUTABLE) $(wildcard *.o)

# Цель для исполняемого файла: собирается из объектных файлов и библиотек
# В зависимостях:
#	$(OBJECTS)	- вызывает правило ".cpp.o" для всех .cpp файлов и делает из них ".o" файлы
$(EXECUTABLE): $(OBJECTS)
	@echo "-- Building target : \"$(EXECUTABLE): $(OBJECTS)\""
	@echo "-- Running command :"
	$(CXX) $(LDLIBS) $(OBJECTS) -o $@

# Правило, автоматически срабатывающее для всех .o файлов, указанных в качестве зависимости к цели
.cpp.o: $(INCLUDES)
	@echo "-- Building target : \".cpp.o: $(INCLUDES)\""
	@echo "-- CXX             : $(CXX)"
	@echo "-- CXXFLAGS        : $(CXXFLAGS)"
	@echo "-- INCLUDES        : $(INCLUDES)"
	@echo "-- Running command :"
	$(CXX) $(CXXFLAGS) -c $< -o $@
