### Системные требования

### Операционная система
- Windows 10 или выше (64-битная версия)

### Необходимые компоненты
- Microsoft Visual C++ Redistributable для Visual Studio 2022

### Qt Библиотеки
#### Если компоненты Qt не установлены:
- Все необходимые библиотеки Qt (Core, Gui, Widgets) включены в репозиторий и должны находиться в той же папке, что и исполняемый файл (.exe).
#### Если компоненты Qt были установлены рано:
- Убедитесь, что в переменную окружения PATH добавлен путь к нужным компонентам Qt. Например, "C:\Qt\6.x.x\msvc2022_64\bin".

### Совместимость
- Скомпилированный проект работает только на 64-битных версиях Windows. Если вы хотите запускать проект на 32-битных системах, потребуется перекомпиляция под 32-битную версию.

### Установка
Клонирование репозитория и сборка:
```bash
   git clone https://github.com/pavel-senin/simple_ctl.git
   cmake simple_ctl
   cmake --build . --config Release
```


### System Requirements
### Operating System
- Windows 10 or higher (64-bit version)
### Required Components
- Microsoft Visual C++ Redistributable for Visual Studio 2022
### Qt Libraries
#### If Qt components are not installed:
- All required Qt libraries (Core, Gui, Widgets) are included in the repository and should be in the same folder as the executable file (.exe).
#### If Qt components were installed earlier:
- Make sure the path to the required Qt components is added to the PATH environment variable. For example, "C:\Qt\6.x.x\msvc2022_64\bin".
### Compatibility
- The compiled project works only on 64-bit versions of Windows. If you want to run the project on 32-bit systems, recompilation for the 32-bit version will be required.

### Installation
Clone and build:
```bash
   git clone https://github.com/pavel-senin/simple_ctl.git
   cmake simple_ctl
   cmake --build . --config Release
```
