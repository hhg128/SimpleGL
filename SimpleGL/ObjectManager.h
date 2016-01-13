#pragma once

namespace SimpleGL
{
	class Object;

	class ObjectIdGenerator
	{
	public:
		static INT64 Generate() { return ++m_nId; }

	private:
		static INT64 m_nId;
	};

	class ObjectManager
	{
	public:
		ObjectManager();
		~ObjectManager();

		Object* CreateObject(void);
		Object* CreateObject(const INT64 nObjectId);

		void Tick();
		void Render();

	private:
		void AddObejct(const INT64 nId, class Object* pObject);
		void RemoveObject(const INT64 nDelObjectId);

	private:
		std::map<INT64, class Object*> ObjectMap;
	};
}