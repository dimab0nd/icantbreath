#include "dropsitems.h"

DropsItems::DropsItems(QWidget * parent)
{
    QPixmap floyd(":/images/images/kfc_food_PNG2.png");
    floyd = floyd.scaled(100, 100, Qt::KeepAspectRatioByExpanding);
    setPixmap(floyd);
}
