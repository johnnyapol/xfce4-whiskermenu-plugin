// Copyright (C) 2013 Graeme Gott <graeme@gottcode.org>
//
// This library is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 2 of the License, or
// at your option) any later version.
//
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this library.  If not, see <http://www.gnu.org/licenses/>.


#ifndef WHISKERMENU_QUERY_HPP
#define WHISKERMENU_QUERY_HPP

#include <string>
#include <vector>

namespace WhiskerMenu
{

class Query
{
public:
	Query(const std::string& query = std::string());
	~Query();

	bool empty() const
	{
		return m_query.empty();
	}

	unsigned int match(const std::string& haystack) const;

	std::string query() const
	{
		return m_query;
	}

	void clear();
	void set(const std::string& query);

private:
	std::string m_query;
	std::vector<std::string> m_query_words;
};

}

#endif // WHISKERMENU_QUERY_HPP
