#define DllExport __declspec( dllexport )

#define DllImport __declspec( dllimport )

template <typename T>

class DllExport CDeque

{


	/*member type*/

	typedef typename T value_type;

	/*private member function*/

	/*public member function*/
	enum EINSERTSTATUS
	{
		DEFAULT,
		REVERSEPUSHFRONT,
		REVERSEPUSHBACK
	};
	template<typename T>
	class CDequeDynamicArry
	{

#define SIZEARRAY 4
		typedef typename T* value_type_ptr;
	private:
		int m_VecfrontIndex; //specity dynamic ArrayB
		int m_VecbackIndex;
		int m_ArrfrontIndex;
		int m_ArrbackIndex;
		int m_nSize;
		value_type_ptr* value_type_ptrContainer;
		EINSERTSTATUS m_insertionStatus;

		void assign_Sec_array_to_default(value_type_ptr* container, size_t size)
		{

			for (int iCount = 0; iCount < size; iCount++)container[iCount] = NULL;
		}
		void assig_array_to_default(value_type_ptr valArray)
		{
			for (int iCount = 0;iCount < SIZEARRAY;iCount++)valArray[iCount] = NULL;
		}
	public:
		CDequeDynamicArry() :m_nSize(4)
		{
			value_type_ptrContainer = new value_type_ptr(m_nSize);
			assign_Sec_array_to_default(value_type_ptrContainer, m_nSize);
			m_VecfrontIndex = m_nSize / 2;
			m_VecbackIndex = m_VecfrontIndex - 1;
			m_ArrbackIndex = SIZEARRAY - 1;
			m_ArrfrontIndex = 0;
			//creation of new array blocks 1.for forward insertion 2. for backword insertion ..........default block size to  be decide
			value_type_ptrContainer[m_VecbackIndex] = new value_type[SIZEARRAY];
			value_type_ptrContainer[m_VecfrontIndex] = new value_type[SIZEARRAY];
			assign_Sec_array_to_default(value);
			assig_array_to_default(value_type_ptrContainer[m_VecbackIndex]);
			assig_array_to_default(value_type_ptrContainer[m_VecfrontIndex]);
		}

		CDequeDynamicArry(size_t size) :m_nSize(size)
		{

		}
		const value_type_ptr operator [](int index);
		void reserve(size_t size);
		bool InsertValueFront(const value_type& elem)
		{
			bool returnValue = false;
			if (m_ArrfrontIndex == SIZEARRAY)//full  primary array for full insertion
			{
				if (abs(m_VecbackIndex - m_VecfrontIndex)>1)// create new primary array and inserting its pointer to secondary array
				{
					value_type_ptr ptrNewArray = new value_type_ptr[SIZEARRAY];
					ptrNewArray[0] = elem;
					push_front(ptrNewArray);
					m_ArrfrontIndex == 1;
				}
			}
			else
			{
				value_type_ptr ptrArray = value_type_ptrContainer[m_VecfrontIndex];
				ptrArray[m_ArrfrontIndex] = elem;
				m_ArrbackIndex++;
				returnValue = true;
			}
			return returnValue;
		}
		bool InsertValueBack(const value_type& elem)
		{
			bool returnValue = false;
			if (m_ArrbackIndex == 0)//full primary array for backinsertion
			{
				if(abs(m_VecbackIndex - m_VecfrontIndex) >1)// create new primary array and insert its pointer to secondary array
				{ 
					value_type_ptr ptrNewArray = new value_type_ptr[SIZEARRAY];
					ptrNewArray[SIZEARRAY - 1] = elem;
					push_back(ptrNewArray);
					m_ArrbackIndex = SIZEARRAY - 2;
				}
			}
			else
			{
				value_type_ptr ptrArray = value_type_ptrContainer[m_VecbackIndex];
				ptrArray[m_ArrbackIndex] = elem;
				m_ArrbackIndex--;
				returnValue = true;

			}

			return returnValue;
		}
		void Remove_Back()
		{
			if (m_ArrbackIndex == SIZEARRAY) // if removing element from primary arry need to remove it from secondary array;
			{
				delete value_type_ptrContainer[m_VecbackIndex - 1][m_ArrbackIndex - 1];
				delete value_type_ptrContainer[m_VecbackIndex - 1];
				if (m_VecbackIndex == m_VecfrontIndex)
				{
					//empty dequeie
					reset();
				}
				else
				{
					m_VecbackIndex++;
				}
				m_ArrbackIndex = 0;
			}
			else // simply remover elem from the arary;
			{
				delete value_type_ptrContainer[m_VecbackIndex - 1][m_ArrbackIndex - 1];
				m_ArrbackIndex++;
			}
			
		}
		inline void setBackIndex(int nBackIndex)
		{
			m_VecbackIndex = nBackIndex;
		}
		inline void setFrontIndex(int nFrontIndex)
		{
			m_VecfrontIndex = nFrontIndex;
		}
		void InsertBack(const value_type_ptr ptrElem, int indexLocation)
		{
			value_type_ptrContainer[indexLocation];
		}
		void InsertFront(const value_type_ptr ptrElem, int indexLocation)
		{
			value_type_ptrContainer[indexLocation];
		}
		void push_back(const value_type_ptr& elem)
		{
			value_type_ptrContainer[m_VecbackIndex] = elem;
			m_VecbackIndex = (m_VecbackIndex - 1) % m_nSize;
		}
		void push_front(const value_type_ptr& elem)
		{
			value_type_ptrContainer[m_VecfrontIndex] = elem;
			m_VecfrontIndex = (m_VecfrontIndex + 1) % m_nSize;
		}
		void Remove();
		void resize();
		inline int size() { return m_nSize; }
	};

	/*private member variable*/

private:
	CDequeDynamicArry<value_type>* ptrDynaicQueue;
	CDequeDynamicArry<value_type>* ptrTempDynaicQueue;

public:
	CDeque();
	~CDeque();
	void push_back(const value_type & val);
	void pop_back();
	void push_front(const value_type & val);
	void pop_front();
	value_type& front();
	value_type& back();
	value_type& operator[](int index);
};

template<typename T>
inline CDeque<T>::CDeque()
{
	ptrDynaicQueue = new CDequeDynamicArry();
	ptrTempDynaicQueue = new CDequeDynamicArry(ptrDynaicQueue->Size() * 2);

}

template<typename T>
inline CDeque<T>::~CDeque()

{

}

template<typename T>
inline void CDeque<T>::push_back(const value_type & val)
{
	bool bStatus = ptrDynaicQueue->InsertValueBack(val);
	//case of filled Primary array
	//create new primary array
	//update both ptrDynamicQueue and ptrTempDynamicQueue
	if (!bStatus)
	{
		//case of filled ptrDynamic Queue
		if (abs(ptrDynaicQueue->m_VecbackIndex - ptrDynaicQueue->m_VecfrontIndex) <= 1)
		{
			//
			
			delete ptrDynaicQueue;
			ptrDynaicQueue = ptrTempDynaicQueue;
			ptrTempDynaicQueue = new CDequeDynamicArry(ptrDynaicQueue->size() * 2);

			int back_index = 0;
			int front_index = 0;
			//case of cycle. either in push_back index or in push_front index
			if (ptrDynaicQueue->m_VecbackIndex > ptrDynaicQueue->m_VecfrontIndex)
			{
				//case of push_back cycle
				if (ptrDynaicQueue->m_VecbackIndex > ptrDynaicQueue->size() / 2)
				{
					back_index = ptrTempDynaicQueue->size() / 2 - ptrDynaicQueue->size() / 2 + (ptrDynaicQueue->size() - ptrDynaicQueue->m_VecbackIndex);
					front_index = ptrTempDynaicQueue->size() / 2 + (ptrDynaicQueue->m_VecfrontIndex - ptrDynaicQueue->size());
				}
				else//case of push_front cycle
				{
					back_index = ptrTempDynaicQueue->size() / 2 - (ptrDynaicQueue->size() / 2 - ptrDynaicQueue->m_VecbackIndex);
					front_index = ptrTempDynaicQueue->size() / 2 + ptrDynaicQueue->m_VecfrontIndex; -ptrDynaicQueue->size() / 2;
				}
			}
			else//normal case;
			{
				front_index = ptrTempDynaicQueue->size() / 2 + (ptrDynaicQueue->m_VecfrontIndex - ptrDynaicQueue->size());
				back_index = ptrTempDynaicQueue->size() / 2 - (ptrDynaicQueue->size() / 2 - ptrDynaicQueue->m_VecbackIndex);
			}
			ptrTempDynaicQueue->setBackIndex(back_index);
			ptrTempDynaicQueue->setFrontIndex(front_index);
			push_back(val);
		}
		//case of unfilled ptrDynamic Queue
		else
		{
			int iIndex = 0;
			if (ptrDynaicQueue->m_insertionStatus == EINSERTSTATUS::REVERSEPUSHBACK)
			{
				iIndex = (3 * ptrDynaicQueue->size()) / 2 - ptrDynaicQueue->m_VecbackIndex;
			}
			else
			{
				index = ptrDynaicQueue->m_VecbackIndex;
			}
			ptrTempDynaicQueue->push_back(ptrDynaicQueue[iIndex])
			ptrTempDynaicQueue->InsertBack(ptrDynaicQueue[iIndex / 2], iIndex / 2)

		}
	}
}

template<typename T>
inline void CDeque<T>::pop_back()//deleting element from back
{
	ptrDynaicQueue->Remove_Back();
}

template<typename T>
inline void CDeque<T>::push_front(const value_type & val)
{
	bool bStatus = ptrDynaicQueue->InsertValueFront(val);
	if (!bStatus)
	{
		//case of filled ptrDynamic Queue
		if (abs(ptrDynaicQueue->m_VecbackIndex - ptrDynaicQueue->m_VecfrontIndex) <= 1)
		{
			delete ptrDynaicQueue;
			ptrDynaicQueue = ptrTempDynaicQueue;
			ptrTempDynaicQueue = new CDequeDynamicArry(ptrDynaicQueue->size() * 2);

			int back_index = 0;
			int front_index = 0;
			//case of cycle. either in push_back index or in push_front index
			if (ptrDynaicQueue->m_VecbackIndex > ptrDynaicQueue->m_VecfrontIndex)
			{
				//case of push_back cycle
				if (ptrDynaicQueue->m_VecbackIndex > ptrDynaicQueue->size() / 2)
				{
					back_index = ptrTempDynaicQueue->size() / 2 - ptrDynaicQueue->size() / 2 + (ptrDynaicQueue->size() - ptrDynaicQueue->m_VecbackIndex);
					front_index = ptrTempDynaicQueue->size() / 2 + (ptrDynaicQueue->m_VecfrontIndex - ptrDynaicQueue->size());
				}
				else//case of push_front cycle
				{
					back_index = ptrTempDynaicQueue->size() / 2 - (ptrDynaicQueue->size() / 2 - ptrDynaicQueue->m_VecbackIndex);
					front_index = ptrTempDynaicQueue->size() / 2 + ptrDynaicQueue->m_VecfrontIndex; -ptrDynaicQueue->size() / 2;
				}
			}
			else//normal case;
			{
				front_index = ptrTempDynaicQueue->size() / 2 + (ptrDynaicQueue->m_VecfrontIndex - ptrDynaicQueue->size());
				back_index = ptrTempDynaicQueue->size() / 2 - (ptrDynaicQueue->size() / 2 - ptrDynaicQueue->m_VecbackIndex);
			}
			ptrTempDynaicQueue->setBackIndex(back_index);
			ptrTempDynaicQueue->setFrontIndex(front_index);
			push_front(val);
		}
		else // case of unfilled ptrDynamic Queue
		{
			int iIndex = 0;
			if (ptrDynaicQueue->m_insertionStatus == EINSERTSTATUS::REVERSEPUSHFRONT)
			{
				iIndex =  ptrDynaicQueue->size() / 2 + ptrDynaicQueue->m_VecfrontIndex;
			}
			else
			{
				index = ptrDynaicQueue->m_VecfrontIndex;
			}
			ptrTempDynaicQueue->push_back(ptrDynaicQueue[iIndex])
			ptrTempDynaicQueue->InsertBack(ptrDynaicQueue[iIndex / 2], iIndex / 2)

		}

	}

}

template<typename T>
inline void CDeque<T>::pop_front()
{

}

template<typename T>
typename CDeque<T>::value_type & CDeque<T>::front()

{

	// TODO: insert return statement here

}

template<typename T>
typename CDeque<T>::value_type & CDeque<T>::back()
{

	// TODO: insert return statement here

}

template<typename T>
typename CDeque<T>::value_type & CDeque<T>::operator[](int index)
{
	// TODO: insert return statement here
}
