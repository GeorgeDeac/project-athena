//
//  ShapeManager.h
//  libraries/physics/src
//
//  Created by Andrew Meadows 2014.10.29
//  Copyright 2014 High Fidelity, Inc.
//
//  Distributed under the Apache License, Version 2.0.
//  See the accompanying file LICENSE or http://www.apache.org/licenses/LICENSE-2.0.html
//

#ifndef hifi_ShapeManager_h
#define hifi_ShapeManager_h

#include <btBulletDynamicsCommon.h>
#include <LinearMath/btHashMap.h>

#include <ShapeInfo.h>

#include "HashKey.h"

class ShapeManager {
public:

    ShapeManager();
    ~ShapeManager();

    /// \return pointer to shape
    const btCollisionShape* getShape(const ShapeInfo& info);

    /// \return true if shape was found and released
    bool releaseShape(const btCollisionShape* shape);

    /// delete shapes that have zero references
    void collectGarbage();

    // validation methods
    int getNumShapes() const { return _shapeMap.size(); }
    int getNumReferences(const ShapeInfo& info) const;
    int getNumReferences(const btCollisionShape* shape) const;
    bool hasShape(const btCollisionShape* shape) const;

private:
    bool releaseShapeByKey(const HashKey& key);

    class ShapeReference {
    public:
        int refCount;
        const btCollisionShape* shape;
        HashKey key;
        ShapeReference() : refCount(0), shape(nullptr) {}
    };

    btHashMap<HashKey, ShapeReference> _shapeMap;
    btAlignedObjectArray<HashKey> _pendingGarbage;
};

#endif // hifi_ShapeManager_h
