#include "stdafx.h"
#include "Object.h"
#include "RHIDX11.h"
#include "TestModel.h"

namespace SimpleGL
{
	Object::Object()
	{
	}


	Object::~Object()
	{
	}

	void Object::Initialize()
	{
		Model = new TriangleModel;
		Model->Initialize();
	}

	void Object::Finalize()
	{
		Model->Finalize();
		delete Model;
	}

	void Object::Tick()
	{

	}

	void Object::Render()
	{

	}

}