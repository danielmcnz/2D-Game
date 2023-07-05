#include "Renderer/Buffer.h"

#ifdef CGR_OPENGL
	#include "OpenGL/OpenGLBuffer.h"
#endif

namespace CGR
{
	VertexBuffer* VertexBuffer::Create(uint32_t size)
	{
	#ifdef CGR_OPENGL
		return new OpenGLVertexBuffer(size);
	#endif
	}

	VertexBuffer* VertexBuffer::Create(float* data, uint32_t size)
	{
	#ifdef CGR_OPENGL
		return new OpenGLVertexBuffer(data, size);
	#endif
	}

	IndexBuffer* IndexBuffer::Create(uint32_t* data, uint32_t count)
	{
	#ifdef CGR_OPENGL
		return new OpenGLIndexBuffer(data, count);
	#endif
	}
}