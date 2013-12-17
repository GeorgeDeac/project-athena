//
//  ControllerScriptingInterface.h
//  hifi
//
//  Created by Brad Hefta-Gaub on 12/17/13
//  Copyright (c) 2013 HighFidelity, Inc. All rights reserved.
//

#ifndef __hifi__ControllerScriptingInterface__
#define __hifi__ControllerScriptingInterface__

#include <QtCore/QObject>
#include <glm/glm.hpp>

/// handles scripting of input controller commands from JS
class ControllerScriptingInterface : public QObject {
    Q_OBJECT

public slots:
    virtual bool isPrimaryButtonPressed() const = 0;
    virtual glm::vec2 getPrimaryJoystickPosition() const = 0;
};

#endif /* defined(__hifi__ControllerScriptingInterface__) */
