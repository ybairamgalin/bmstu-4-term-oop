#include "transformationDock.h"

static point3d getFields(QLineEdit *first, QLineEdit *second,
                         QLineEdit *third, error &error)
{
    bool converted = true;
    error = OK;
    double x = first->text().toDouble(&converted);

    if (!converted)
        error = NOT_DOUBLE;

    double y = second->text().toDouble(&converted);

    if (!converted)
        error = NOT_DOUBLE;

    double z = third->text().toDouble(&converted);

    if (!converted)
        error = NOT_DOUBLE;

    return point3d{x, y, z};
}

static void allocateFields(transformationDock_t *dock)
{
    dock->translateLabel = new QLabel("Перенос");
    dock->dxEdit = new QLineEdit;
    dock->dxEdit->setPlaceholderText("dx");
    dock->dyEdit = new QLineEdit;
    dock->dyEdit->setPlaceholderText("dy");
    dock->dzEdit = new QLineEdit;
    dock->dzEdit->setPlaceholderText("dz");
    dock->translateButton = new QPushButton("Перенести");

    dock->scaleLabel = new QLabel("Масштабирование");
    dock->kxEdit = new QLineEdit;
    dock->kxEdit->setPlaceholderText("kx");
    dock->kyEdit = new QLineEdit;
    dock->kyEdit->setPlaceholderText("ky");
    dock->kzEdit = new QLineEdit;
    dock->kzEdit->setPlaceholderText("kz");
    dock->scaleButton = new QPushButton("Масштабировать");

    dock->rotateLabel = new QLabel("Поворот");
    dock->rxEdit = new QLineEdit;
    dock->rxEdit->setPlaceholderText("Ox");
    dock->ryEdit = new QLineEdit;
    dock->ryEdit->setPlaceholderText("Oy");
    dock->rzEdit = new QLineEdit;
    dock->rzEdit->setPlaceholderText("Oz");
    dock->rotateButton = new QPushButton("Повернуть");
}

static void placeFields(transformationDock_t *dock)
{
    dock->multiWidget = new QWidget;
    dock->grid = new QGridLayout(dock->multiWidget);

    dock->grid->addWidget(dock->translateLabel, 0, 0, 1, 3);
    dock->grid->addWidget(dock->dxEdit, 1, 0);
    dock->grid->addWidget(dock->dyEdit, 1, 1);
    dock->grid->addWidget(dock->dzEdit, 1, 2);
    dock->grid->addWidget(dock->translateButton, 2, 0, 1, 3);

    dock->grid->addWidget(dock->scaleLabel, 3, 0, 1, 3);
    dock->grid->addWidget(dock->kxEdit, 4, 0);
    dock->grid->addWidget(dock->kyEdit, 4, 1);
    dock->grid->addWidget(dock->kzEdit, 4, 2);
    dock->grid->addWidget(dock->scaleButton, 5, 0, 1, 3);

    dock->grid->addWidget(dock->rotateLabel, 6, 0, 1, 3);
    dock->grid->addWidget(dock->rxEdit, 7, 0);
    dock->grid->addWidget(dock->ryEdit, 7, 1);
    dock->grid->addWidget(dock->rzEdit, 7, 2);
    dock->grid->addWidget(dock->rotateButton, 8, 0, 1, 3);

    dock->dock->setWidget(dock->multiWidget);
}

transformationDock_t *transformationDockCreate(QWidget *parent)
{
    transformationDock_t *dock = new transformationDock;

    dock->dock = new QDockWidget(parent);
    dock->dock->setAllowedAreas(Qt::RightDockWidgetArea);
    dock->dock->setWindowTitle("Операции");
    dock->dock->setMinimumWidth(DOCK_WIDTH);

    allocateFields(dock);
    placeFields(dock);

    return dock;
}

void transformationDockDelete(transformationDock_t *dock)
{
    delete dock;
}

QDockWidget *tranformationGetDock(transformationDock_t *dock)
{
    return dock->dock;
}

QPushButton &getTranslateButton(transformationDock_t &dock)
{
    return *(dock.translateButton);
}

QPushButton &getScaleButton(transformationDock_t &dock)
{
    return *(dock.scaleButton);
}

QPushButton &getRotateButton(transformationDock_t &dock)
{
    return *(dock.rotateButton);
}

point3d getScale(transformationDock_t &dock, error &error)
{
    return getFields(dock.kxEdit, dock.kyEdit, dock.kzEdit, error);
}

point3d getRotation(transformationDock_t &dock, error &error)
{
    return getFields(dock.rxEdit, dock.ryEdit, dock.rzEdit, error);
}

point3d getTranslation(transformationDock_t &dock, error &error)
{
    return getFields(dock.dxEdit, dock.dyEdit, dock.dzEdit, error);
}
