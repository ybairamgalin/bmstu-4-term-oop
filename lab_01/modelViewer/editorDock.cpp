 #include "editorDock.h"

static void allocateFields(editorDock_t *editorDock)
{
    editorDock->addEdgeLabel = new QLabel("Добавление ребра");
    editorDock->x1Edit = new QLineEdit;
    editorDock->x1Edit->setPlaceholderText("x1");
    editorDock->y1Edit = new QLineEdit;
    editorDock->y1Edit->setPlaceholderText("y1");
    editorDock->z1Edit = new QLineEdit;
    editorDock->z1Edit->setPlaceholderText("z1");
    editorDock->x2Edit = new QLineEdit;
    editorDock->x2Edit->setPlaceholderText("x2");
    editorDock->y2Edit = new QLineEdit;
    editorDock->y2Edit->setPlaceholderText("y2");
    editorDock->z2Edit = new QLineEdit;
    editorDock->z2Edit->setPlaceholderText("z2");
    editorDock->addEdgeButton = new QPushButton("Добавить ребро");

    editorDock->edgesList = new QListWidget;
    editorDock->deleteEdgeButton = new QPushButton("Удалить выбранное ребро");
}

static void deleteFields(editorDock_t *editorDock)
{
    delete editorDock->addEdgeLabel;
    delete editorDock->x1Edit;
    delete editorDock->y1Edit;
    delete editorDock->z1Edit;
    delete editorDock->x2Edit;
    delete editorDock->y2Edit;
    delete editorDock->z2Edit;
    delete editorDock->addEdgeButton;
    delete editorDock->edgesList;
    delete editorDock->deleteEdgeButton;

    delete editorDock->grid;

    delete editorDock->dock;
}

static void placeFields(editorDock_t *editorDock)
{
    editorDock->multiWidget = new QWidget;
    editorDock->grid = new QGridLayout(editorDock->multiWidget);

    editorDock->grid->addWidget(editorDock->addEdgeLabel, 0, 0, 1, 3);
    editorDock->grid->addWidget(editorDock->x1Edit, 1, 0);
    editorDock->grid->addWidget(editorDock->y1Edit, 1, 1);
    editorDock->grid->addWidget(editorDock->z1Edit, 1, 2);
    editorDock->grid->addWidget(editorDock->x2Edit, 2, 0);
    editorDock->grid->addWidget(editorDock->y2Edit, 2, 1);
    editorDock->grid->addWidget(editorDock->z2Edit, 2, 2);
    editorDock->grid->addWidget(editorDock->addEdgeButton, 3, 0, 1, 3);

    editorDock->grid->addWidget(editorDock->edgesList, 4, 0, 1, 3);
    editorDock->grid->addWidget(editorDock->deleteEdgeButton, 5, 0, 1, 3);

    editorDock->dock->setWidget(editorDock->multiWidget);
}

editorDock_t *editorDockCreate(QWidget *parent)
{
    editorDock_t *editorDock = new editorDock_t;

    editorDock->dock = new QDockWidget(parent);
    editorDock->dock->setAllowedAreas(Qt::RightDockWidgetArea);
    editorDock->dock->setWindowTitle("Редактор фигуры");
    editorDock->dock->setMinimumWidth(DOCK_WIDTH);

    allocateFields(editorDock);
    placeFields(editorDock);

    return editorDock;
}

void editorDockDelete(editorDock_t *editorDock)
{
    deleteFields(editorDock);
    delete editorDock;
}

QDockWidget *editorGetDock(editorDock_t *editorDock)
{
    return editorDock->dock;
}
