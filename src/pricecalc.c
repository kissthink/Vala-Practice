/* pricecalc.c generated by valac 0.18.1, the Vala compiler
 * generated from pricecalc.vala, do not modify */

/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * main.c
 * Copyright (C) 2013 Matrix <Pigex.Zhang@gmail.com>
 * 
 * PriceCalc is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * PriceCalc is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License along
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <glib.h>
#include <glib-object.h>
#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h>
#include <stdio.h>


#define TYPE_MAIN (main_get_type ())
#define MAIN(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_MAIN, Main))
#define MAIN_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_MAIN, MainClass))
#define IS_MAIN(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_MAIN))
#define IS_MAIN_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_MAIN))
#define MAIN_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_MAIN, MainClass))

typedef struct _Main Main;
typedef struct _MainClass MainClass;
typedef struct _MainPrivate MainPrivate;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _g_error_free0(var) ((var == NULL) ? NULL : (var = (g_error_free (var), NULL)))

struct _Main {
	GObject parent_instance;
	MainPrivate * priv;
};

struct _MainClass {
	GObjectClass parent_class;
};


static gpointer main_parent_class = NULL;

GType main_get_type (void) G_GNUC_CONST;
enum  {
	MAIN_DUMMY_PROPERTY
};
#define MAIN_UI_FILE "src/pricecalc.ui"
Main* main_new (void);
Main* main_construct (GType object_type);
void main_on_destroy (GtkWidget* window, Main* self);
static gint main_main (gchar** args, int args_length1);


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


Main* main_construct (GType object_type) {
	Main * self = NULL;
	GError * _inner_error_ = NULL;
	self = (Main*) g_object_new (object_type, NULL);
	{
		GtkBuilder* _tmp0_;
		GtkBuilder* builder;
		GObject* _tmp1_ = NULL;
		GtkWindow* _tmp2_;
		GtkWindow* window;
		GtkWindow* _tmp3_;
		_tmp0_ = gtk_builder_new ();
		builder = _tmp0_;
		gtk_builder_add_from_file (builder, MAIN_UI_FILE, &_inner_error_);
		if (_inner_error_ != NULL) {
			_g_object_unref0 (builder);
			goto __catch0_g_error;
		}
		gtk_builder_connect_signals (builder, self);
		_tmp1_ = gtk_builder_get_object (builder, "window");
		_tmp2_ = _g_object_ref0 (G_TYPE_CHECK_INSTANCE_TYPE (_tmp1_, GTK_TYPE_WINDOW) ? ((GtkWindow*) _tmp1_) : NULL);
		window = _tmp2_;
		_tmp3_ = window;
		gtk_widget_show_all ((GtkWidget*) _tmp3_);
		_g_object_unref0 (window);
		_g_object_unref0 (builder);
	}
	goto __finally0;
	__catch0_g_error:
	{
		GError* e = NULL;
		FILE* _tmp4_;
		GError* _tmp5_;
		const gchar* _tmp6_;
		e = _inner_error_;
		_inner_error_ = NULL;
		_tmp4_ = stderr;
		_tmp5_ = e;
		_tmp6_ = _tmp5_->message;
		fprintf (_tmp4_, "Could not load UI: %s\n", _tmp6_);
		_g_error_free0 (e);
	}
	__finally0:
	if (_inner_error_ != NULL) {
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return NULL;
	}
	return self;
}


Main* main_new (void) {
	return main_construct (TYPE_MAIN);
}


void main_on_destroy (GtkWidget* window, Main* self) {
	g_return_if_fail (self != NULL);
	g_return_if_fail (window != NULL);
	gtk_main_quit ();
}


static gint main_main (gchar** args, int args_length1) {
	gint result = 0;
	Main* _tmp0_;
	Main* app;
	gtk_init (&args_length1, &args);
	_tmp0_ = main_new ();
	app = _tmp0_;
	gtk_main ();
	result = 0;
	_g_object_unref0 (app);
	return result;
}


int main (int argc, char ** argv) {
	g_type_init ();
	return main_main (argv, argc);
}


static void main_class_init (MainClass * klass) {
	main_parent_class = g_type_class_peek_parent (klass);
}


static void main_instance_init (Main * self) {
}


GType main_get_type (void) {
	static volatile gsize main_type_id__volatile = 0;
	if (g_once_init_enter (&main_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (MainClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) main_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (Main), 0, (GInstanceInitFunc) main_instance_init, NULL };
		GType main_type_id;
		main_type_id = g_type_register_static (G_TYPE_OBJECT, "Main", &g_define_type_info, 0);
		g_once_init_leave (&main_type_id__volatile, main_type_id);
	}
	return main_type_id__volatile;
}



