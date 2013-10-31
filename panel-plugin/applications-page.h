/*
 * Copyright (C) 2013 Graeme Gott <graeme@gottcode.org>
 *
 * This library is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this library.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef WHISKERMENU_APPLICATIONS_PAGE_H
#define WHISKERMENU_APPLICATIONS_PAGE_H

#include "page.h"

#include <map>
#include <string>
#include <vector>

extern "C"
{
#include <garcon/garcon.h>
}

namespace WhiskerMenu
{

class Category;
class Launcher;
class LauncherView;
class SectionButton;

class ApplicationsPage : public Page
{

public:
	explicit ApplicationsPage(Window* window);
	~ApplicationsPage();

	Launcher* get_application(const std::string& desktop_id) const;

	GtkTreeModel* get_model() const
	{
		return m_model;
	}

	void invalidate_applications();
	void load_applications();

	static bool get_load_hierarchy();
	static void set_load_hierarchy(bool load);

private:
	void apply_filter(GtkToggleButton* togglebutton);
	bool on_filter(GtkTreeModel* model, GtkTreeIter* iter);
	void clear_applications();
	void load_menu(GarconMenu* menu, Category* parent_category);
	void load_menu_item(GarconMenuItem* menu_item, Category* category);
	void load_categories();
	void unset_model();

private:
	GarconMenu* m_garcon_menu;
	SectionButton* m_all_button;
	std::vector<Category*> m_categories;
	std::map<std::string, Launcher*> m_items;
	GtkTreeModel* m_model;
	bool m_loaded;


private:
	static void invalidate_applications_slot(ApplicationsPage* obj)
	{
		obj->invalidate_applications();
	}

	static void apply_filter_slot(GtkToggleButton* togglebutton, ApplicationsPage* obj)
	{
		obj->apply_filter(togglebutton);
	}
};

}

#endif // WHISKERMENU_APPLICATIONS_PAGE_H