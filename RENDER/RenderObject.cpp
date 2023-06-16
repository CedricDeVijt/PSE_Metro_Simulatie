#include "RenderObject.h"
#include "Objects/Object3D.h"
#include "Objects/Calculator.h"
#include "Include/vector3d.h"
#include "MetroRenderer.h"
#include "random"

#define randRGB (std::vector<double>{(double)(1+ (rand() % 100))*100, (double)(1+ (rand() % 100))*100, (double)(1+ (rand() % 100))*100})

PCCRender::PCCRender(double x, double y, double z) : RenderObject(x, y, z) {
    size = MetroRenderer::tramSize;
}

AlbatrosRender::AlbatrosRender(double x, double y, double z) : RenderObject(x, y, z) {
    size = MetroRenderer::tramSize;
}

StadsLijnerRender::StadsLijnerRender(double x, double y, double z) : RenderObject(x, y, z) {
    size = MetroRenderer::tramSize;
}

HalteRender::HalteRender(double x, double y, double z) : RenderObject(x, y, z) {
    size = MetroRenderer::tramSize;
}

MetrostationRender::MetrostationRender(double x, double y, double z) : RenderObject(x, y, z) {
    size = MetroRenderer::stationSize;
}

SpoorRender::SpoorRender(double x, double y, double z, double x2, double y2, double z2) : RenderObject(x, y, z), x2(x2),
                                                                                          y2(y2), z2(z2) {
    width = MetroRenderer::spoorWidth;
}

Object3D PCCRender::createRender() const {
    Object3D obj;
    obj = Object3D::Object3DFactory::createCube();
    obj.applyTransformation(Calculator::superMatrix(size, 0, 0, 0, Vector3D::point(getX(), getY(), getZ())));
    obj.ambientReflection = randRGB;
    obj.diffuseReflection = randRGB;
    obj.color = randRGB;
    return obj;
}

Object3D AlbatrosRender::createRender() const {
    Object3D obj;
    obj = Object3D::Object3DFactory::createCube();
    obj.applyTransformation(Calculator::superMatrix(size, 0, 0, 0, Vector3D::point(getX(), getY(), getZ())));
    obj.ambientReflection = randRGB;
    obj.diffuseReflection = randRGB;
    obj.color = randRGB;
    return obj;
}

Object3D StadsLijnerRender::createRender() const {
    Object3D obj;
    obj = Object3D::Object3DFactory::createCube();
    obj.applyTransformation(Calculator::superMatrix(size, 0, 0, 0, Vector3D::point(getX(), getY(), getZ())));
    obj.ambientReflection = randRGB;
    obj.diffuseReflection = randRGB;
    obj.color = randRGB;
    return obj;
}


Object3D HalteRender::createRender() const {
    Object3D obj;
    obj = Object3D::Object3DFactory::loadObj("./RENDER/blends/station.obj");
    obj.applyTransformation(Calculator::superMatrix(size, 0, 0, 0, Vector3D::point(getX(), getY(), getZ())));
    obj.ambientReflection = randRGB;
    obj.diffuseReflection = randRGB;
    obj.color = randRGB;
    return obj;
}


Object3D MetrostationRender::createRender() const {
    Object3D obj;
    obj = Object3D::Object3DFactory::loadObj("./RENDER/blends/station.obj");
    obj.applyTransformation(Calculator::superMatrix(size, 0, 0, 0, Vector3D::point(getX(), getY(), getZ())));
    obj.ambientReflection = randRGB;
    obj.diffuseReflection = randRGB;
    obj.color = randRGB;
    return obj;
}


Object3D SpoorRender::createRender() const {
    Object3D obj;
    obj.vertexes.push_back(Vector3D::point(getX()-width/2, getY()-width/2, getZ()));
    obj.vertexes.push_back(Vector3D::point(getX()+width/2, getY()+width/2, getZ()));
    obj.vertexes.push_back(Vector3D::point(x2+width/2, y2+width/2, z2));
    obj.vertexes.push_back(Vector3D::point(x2-width/2, y2-width/2, z2));
    obj.faces.push_back(Face({0,1,2,3}));

    obj.ambientReflection = randRGB;
    obj.diffuseReflection = randRGB;
    obj.color = randRGB;
    return obj;
}

