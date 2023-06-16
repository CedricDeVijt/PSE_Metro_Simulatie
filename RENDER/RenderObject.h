#ifndef ENGINE_RENDEROBJECT_H
#define ENGINE_RENDEROBJECT_H

#include "./Objects/Object3D.h"


class RenderObject {
public:
    RenderObject(double x, double y, double z) : x(x), y(y), z(z), _initCheck(this) {}

    bool properlyInitialized() const {
        return _initCheck==this;
    }

    double getX() const {
        return x;
    }

    double getY() const {
        return y;
    }

    double getZ() const {
        return z;
    }

    virtual Object3D createRender() const =0 ;
private:
    double x;
    double y;
    double z;
    RenderObject *_initCheck;
};

class SpoorRender : public RenderObject {
public:
    SpoorRender(double x, double y, double z, double x2, double y2, double z2);
    Object3D createRender() const override;
private:
    double x2;
    double y2;
    double z2;
    int width;
};

class PCCRender : public RenderObject {
public:
    PCCRender(double x, double y, double z);
    Object3D createRender() const override;
private:
    int size;
};

class AlbatrosRender : public RenderObject {
public:
    AlbatrosRender(double x, double y, double z);
    Object3D createRender() const override;
private:
    int size;
};

class StadsLijnerRender : public RenderObject {
public:
    StadsLijnerRender(double x, double y, double z);
    Object3D createRender() const override;
private:
    int size;
};

class HalteRender : public RenderObject {
public:
    HalteRender(double x, double y, double z);
    Object3D createRender() const override;
private:
    int size;
};

class MetrostationRender : public RenderObject {
public:
    MetrostationRender(double x, double y, double z);
    Object3D createRender() const override;
private:
    int size;
};

#endif //ENGINE_RENDEROBJECT_H
