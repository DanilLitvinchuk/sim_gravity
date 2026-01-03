# sim_gravity

ОПИСАНИЕ

Это разработанный мной симулятор гравитации в космосе.

ПОДГОТОВКА

Для запуска вам потребуется графическая библиотека SFML версии 2.6.
Установка для arch-based дистрибутивов (используя yay):
`yay -S sfml2`

ЗАПУСК

Команды для компиляции и запуска:

```bash
g++ main.cpp -o sfml-app -I/opt/sfml2/include -L/opt/sfml2/lib -lsfml-graphics -lsfml-window -lsfml-system 
LD_LIBRARY_PATH=/opt/sfml2/lib ./sfml-app 
