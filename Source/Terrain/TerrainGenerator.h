#ifndef TERRAINGENERATOR_H_INCLUDED
#define TERRAINGENERATOR_H_INCLUDED

#include <functional>
#include "../Model/Mesh.h"
#include "Terrain.h"

Mesh generateTerrain(HeightFunction heightFunction);


#endif // TERRAINGENERATOR_H_INCLUDED
