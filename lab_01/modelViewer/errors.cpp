#include "errors.h"

void showWarning(notifier notify, const error &error)
{
    switch (error)
    {
    case OK:
        break;
    case NO_SUCH_FILE:
        notify("Файл не найден");
        break;
    case P1_FIELDS:
        notify("Проверьте координаты точки 1");
        break;
    case P2_FIELDS:
        notify("Проверьте координаты точки 2");
        break;
    case NOT_DOUBLE:
        notify("Проверьте поля");
        break;
    case NOT_EDGE:
        notify("Линия вырождена в точку");
        break;
    default:
        notify("Неизвестная ошибка");
    }
}
