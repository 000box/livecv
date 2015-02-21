#ifndef QDRAWMATCHES_HPP
#define QDRAWMATCHES_HPP

#include "QMatDisplay.hpp"
#include "QKeyPointVector.hpp"
#include "QDMatchVector.hpp"

class QDrawMatches : public QMatDisplay{

    Q_OBJECT
    Q_PROPERTY(QMat*            img1        READ img1        WRITE setImg1        NOTIFY img1Changed)
    Q_PROPERTY(QKeyPointVector* keypoints1  READ keypoints1  WRITE setKeypoints1  NOTIFY keypoints1Changed)
    Q_PROPERTY(QMat*            img2        READ img2        WRITE setImg2        NOTIFY img2Changed)
    Q_PROPERTY(QKeyPointVector* keypoints2  READ keypoints2  WRITE setKeypoints2  NOTIFY keypoints2Changed)
    Q_PROPERTY(QDMatchVector*   matches1to2 READ matches1to2 WRITE setMatches1to2 NOTIFY matches1to2Changed)

public:
    explicit QDrawMatches(QQuickItem *parent = 0);
    virtual ~QDrawMatches();

    QMat* img1();
    void setImg1(QMat* img1);

    QKeyPointVector* keypoints1();
    void setKeypoints1(QKeyPointVector* keypoints1);

    QMat* img2();
    void setImg2(QMat* img2);

    QKeyPointVector* keypoints2();
    void setKeypoints2(QKeyPointVector* keypoints2);

    QDMatchVector* matches1to2();
    void setMatches1to2(QDMatchVector* matches1to2);

protected:
    virtual QSGNode *updatePaintNode(QSGNode *node, UpdatePaintNodeData *nodeData);

signals:
    void img1Changed();
    void keypoints1Changed();
    void img2Changed();
    void keypoints2Changed();
    void matches1to2Changed();

public slots:

private:
    QMat*            m_img1;
    QMat*            m_img1Internal;
    QMat*            m_img2;
    QMat*            m_img2Internal;
    QKeyPointVector* m_keypoints1;
    QKeyPointVector* m_keypoints2;
    QDMatchVector*   m_matches;

    bool             m_matchSurfaceDirty;
};

inline QMat *QDrawMatches::img1(){
    return m_img1;
}

inline void QDrawMatches::setImg1(QMat *img1){
    m_img1 = img1;
    emit img1Changed();
    m_matchSurfaceDirty = true;
    update();
}

inline QKeyPointVector *QDrawMatches::keypoints1(){
    return m_keypoints1;
}

inline void QDrawMatches::setKeypoints1(QKeyPointVector *keypoints1){
    m_keypoints1 = keypoints1;
    emit keypoints1Changed();
    m_matchSurfaceDirty = true;
    update();
}

inline QMat *QDrawMatches::img2(){
    return m_img2;
}

inline void QDrawMatches::setImg2(QMat *img2){
    m_img2 = img2;
    emit img2Changed();
    m_matchSurfaceDirty = true;
    update();
}

inline QKeyPointVector *QDrawMatches::keypoints2(){
    return m_keypoints2;
}

inline void QDrawMatches::setKeypoints2(QKeyPointVector *keypoints2){
    m_keypoints2 = keypoints2;
    emit keypoints2Changed();
    m_matchSurfaceDirty = true;
    update();
}

inline QDMatchVector *QDrawMatches::matches1to2(){
    return m_matches;
}

inline void QDrawMatches::setMatches1to2(QDMatchVector *matches1to2){
    m_matches = matches1to2;
    emit matches1to2Changed();
    m_matchSurfaceDirty = true;
    update();
}

#endif // QDRAWMATCHES_HPP
