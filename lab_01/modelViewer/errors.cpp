#include "errors.h"

void showWarning(QWidget *parent, const error &error)
{
    switch (error)
    {
    case OK:
        break;
    case NO_SUCH_FILE:
        QMessageBox::warning(parent, "Warning", "Файл не найден");
        break;
    case P1_FIELDS:
        QMessageBox::warning(parent, "Warning", "Проверьте координаты точки 1");
        break;
    case P2_FIELDS:
        QMessageBox::warning(parent, "Warning", "Проверьте координаты точки 2");
        break;
    case NOT_DOUBLE:
        QMessageBox::warning(parent, "Warning", "Проверьте поля");
        break;
    default:
        QMessageBox::warning(parent, "Warning", "Неизвестная ошибка");
    }
}
