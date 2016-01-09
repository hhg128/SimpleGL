#pragma once

namespace SimpleGL
{
	class ObjectIdGenerator
	{
	public:
		static INT64 Generate() { return ++m_nId; }

	private:
		static INT64 m_nId;
	};

	INT64 ObjectIdGenerator::m_nId = 0;

	class ObjectManager
	{
	public:
		ObjectManager();
		~ObjectManager();

		void CreateObject(void);
		void CreateObject(const INT64 nObjectId);

	private:
		void AddObejct(const INT64 nId, class Object* pObject);
		void RemoveObject(const INT64 nDelObjectId);

	private:
		std::map<INT64, class Object*> ObjectMap;
	};
}