/*
 * Copyright (C) 2019 Graeme Gott <graeme@gottcode.org>
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

#ifndef WHISKERMENU_LAUNCHER_ICON_VIEW_H
#define WHISKERMENU_LAUNCHER_ICON_VIEW_H

#include "launcher-view.h"

namespace WhiskerMenu
{

class LauncherIconView : public LauncherView
{
public:
	LauncherIconView();
	~LauncherIconView();

	GtkWidget* get_widget() const
	{
		return GTK_WIDGET(m_view);
	}

	GtkTreePath* get_cursor() const;
	GtkTreePath* get_path_at_pos(int x, int y) const;
	GtkTreePath* get_selected_path() const;
	void activate_path(GtkTreePath* path);
	void select_path(GtkTreePath* path);
	void set_cursor(GtkTreePath* path);

	void set_fixed_height_mode(bool fixed_height);
	void set_selection_mode(GtkSelectionMode mode);

	void hide_tooltips();
	void show_tooltips();

	void clear_selection();
	void collapse_all();

	void set_model(GtkTreeModel* model);
	void unset_model();

	void set_drag_source(GdkModifierType start_button_mask, const GtkTargetEntry* targets, gint n_targets, GdkDragAction actions);
	void set_drag_dest(const GtkTargetEntry* targets, gint n_targets, GdkDragAction actions);
	void unset_drag_source();
	void unset_drag_dest();

	void reload_icon_size();

private:
	gboolean on_leave_notify_event(GtkWidget*, GdkEvent*);
	gboolean on_motion_notify_event(GtkWidget*, GdkEvent* event);
	gboolean on_scroll_event(GtkWidget*, GdkEvent* event);
	void select_path_at_pos(int x, int y);

private:
	GtkIconView* m_view;
	GtkCellRenderer* m_icon_renderer;
	int m_icon_size;
};

}

#endif // WHISKERMENU_LAUNCHER_ICON_VIEW_H
