#pragma once

//--- Chunginator Constants ----//

#define CGR_OPENGL

//---- Graphics API Includes ----//

#ifdef _WIN32
	#ifdef CGR_OPENGL
		#include <glad/glad.h>
		#include <GLFW/glfw3.h>
	#else
		#error "graphics api not supported"
	#endif
#else
	#error "os not supported"
#endif

//--- 3rd Party Includes  ----//

// GLM //

#include <glm/glm.hpp>
#include <glm/vec4.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

// STB Image //

#include <STB_IMAGE/stb_image.h>

//---- Chunginator Includes ----//

#include "Math/Vec2.h"
#include "Math/Vec3.h"
#include "Math/Vec4.h"

//---- Standard Includes ----//

#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>