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

static point3d getP1(const editorDock_t &editorDock, error &error)
{
    bool converted = true;
    error = OK;
    double x = editorDock.x1Edit->text().toDouble(&converted);

    if (!converted)
        error = P1_FIELDS;

    double y = editorDock.y1Edit->text().toDouble(&converted);

    if (!converted)
        error = P1_FIELDS;

    double z = editorDock.z1Edit->text().toDouble(&converted);

    if (!converted)
        error = P1_FIELDS;

    return point3dInit(x, y, z);
}

static point3d getP2(const editorDock_t &editorDock, error &error)
{
    bool converted = true;
    error = OK;
    double x = editorDock.x2Edit->text().toDouble(&converted);

    if (!converted)
        error = P2_FIELDS;

    double y = editorDock.y2Edit->text().toDouble(&converted);

    if (!converted)
        error = P2_FIELDS;

    double z = editorDock.z2Edit->text().toDouble(&converted);

    if (!converted)
        error = P2_FIELDS;

    return point3dInit(x, y, z);
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

QPushButton &getAddEdgeButton(editorDock_t &dock)
{
    return *(dock.addEdgeButton);
}

QPushButton &getDeleteButton(editorDock &dock)
{
    return *(dock.deleteEdgeButton);
}

edge_t getNewEdge(const editorDock_t &dock, error &error)
{
    point3d p1 = getP1(dock, error);

    if (error)
        return edgeInit(point3dInit(0, 0, 0), point3dInit(0, 0, 0));

    point3d p2 = getP2(dock, error);

    if (error)
        return edgeInit(point3dInit(0, 0, 0), point3dInit(0, 0, 0));
  
    return edgeInit(p1, p2);
}

void editorDockUpdate(editorDock_t &dock, const figure_t &figure)
{
    dock.edgesList->clear();
    int lng = getLng(figure);

    for (int i = 0; i < lng; i++)
    {
        edge_t edge = getEdge(figure, i);

        dock.edgesList->addItem(toQString(edge.p1) + " <-> " + toQString(edge.p2));
    }
}
