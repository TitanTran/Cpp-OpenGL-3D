#pragma once
#include <OGL3D/OPrerequisites.h>

class OVertexArrayObject
{
public:
	OVertexArrayObject(const OVertexBufferData& data);
	~OVertexArrayObject();

	ui32 getId();

	ui32 getVertexBufferSize();
	ui32 getVertexSize();

private:
	ui32 m_vertexBufferId = 0;
	ui32 m_vertexArrayObjectId = 0;
	OVertexBufferData m_vertexBufferData;
};

