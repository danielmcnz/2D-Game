#include "Renderer/VertexArray.h"

#ifdef CGR_OPENGL
	#include "OpenGL/OpenGLVertexArray.h"
#endif

namespace CGR
{
	VertexArray* VertexArray::Create() 
	{
	#ifdef CGR_OPENGL
		return new OpenGLVertexArray();
	#endif
	}
}