#include "QKeyPointVector.hpp"
#include <QQmlEngine>

QKeyPointVector::QKeyPointVector(QQuickItem *parent) :
    QQuickItem(parent)
{
    setFlag(QQuickItem::ItemHasContents, false);
}

QKeyPointVector::~QKeyPointVector(){
}

QKeyPointVector* QKeyPointVector::createOwnedObject(){
    QKeyPointVector* ownedObject = new QKeyPointVector;
    ownedObject->m_keyPoints     = m_keyPoints;
    QQmlEngine::setObjectOwnership(ownedObject, QQmlEngine::JavaScriptOwnership);
    return ownedObject;
}
