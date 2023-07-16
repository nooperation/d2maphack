#ifndef __AUTO_LIST_H__
#define __AUTO_LIST_H__

#pragma warning( disable : 4786)
#include <algorithm>
#include <set>
#include <functional>
#include "men_fun_bind.h"


template<class Cont>
class AutoList : public std::set<typename Cont::key_type>
{
public:
	explicit AutoList(Cont& x) : cont_(x)
	{
		for (const auto& item : cont_)
		{
			this->insert(item.first);
		}
	}

	~AutoList()
	{
		while (!this->empty())
		{
			this->erase(this->begin());
		}
	}

private:
	void insert_element(typename Cont::const_reference val)
	{
		insert(val.first);
	}
	void erase_element(const_reference val)
	{
		cont_.erase(val);
	}
public:
	bool test_element(const_reference val)
	{
		return find(val) != end();
	}
private:
	Cont& cont_;
};

#endif // __AUTO_LIST_H__
