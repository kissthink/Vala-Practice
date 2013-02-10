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
#include <gtk/gtk.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <float.h>
#include <math.h>


#define TYPE_MAIN_WINDOW (main_window_get_type ())
#define MAIN_WINDOW(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_MAIN_WINDOW, MainWindow))
#define MAIN_WINDOW_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_MAIN_WINDOW, MainWindowClass))
#define IS_MAIN_WINDOW(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_MAIN_WINDOW))
#define IS_MAIN_WINDOW_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_MAIN_WINDOW))
#define MAIN_WINDOW_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_MAIN_WINDOW, MainWindowClass))

typedef struct _MainWindow MainWindow;
typedef struct _MainWindowClass MainWindowClass;
typedef struct _MainWindowPrivate MainWindowPrivate;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _g_error_free0(var) ((var == NULL) ? NULL : (var = (g_error_free (var), NULL)))
#define _g_free0(var) (var = (g_free (var), NULL))

#define TYPE_DISCOUNT (discount_get_type ())
#define DISCOUNT(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_DISCOUNT, Discount))
#define DISCOUNT_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_DISCOUNT, DiscountClass))
#define IS_DISCOUNT(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_DISCOUNT))
#define IS_DISCOUNT_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_DISCOUNT))
#define DISCOUNT_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_DISCOUNT, DiscountClass))

typedef struct _Discount Discount;
typedef struct _DiscountClass DiscountClass;
#define _vala_assert(expr, msg) if G_LIKELY (expr) ; else g_assertion_message_expr (G_LOG_DOMAIN, __FILE__, __LINE__, G_STRFUNC, msg);

struct _MainWindow {
	GObject parent_instance;
	MainWindowPrivate * priv;
};

struct _MainWindowClass {
	GObjectClass parent_class;
};

struct _MainWindowPrivate {
	GtkEntry* _entry_price;
	GtkEntry* _entry_number;
	GtkTextView* _textview_output;
	GtkComboBox* _combobox_discount;
};


static gpointer main_window_parent_class = NULL;

GType main_window_get_type (void) G_GNUC_CONST;
#define MAIN_WINDOW_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), TYPE_MAIN_WINDOW, MainWindowPrivate))
enum  {
	MAIN_WINDOW_DUMMY_PROPERTY,
	MAIN_WINDOW_ENTRY_PRICE,
	MAIN_WINDOW_ENTRY_NUMBER,
	MAIN_WINDOW_TEXTVIEW_OUTPUT,
	MAIN_WINDOW_COMBOBOX_DISCOUNT
};
#define MAIN_WINDOW_UI_FILE "src/pricecalc.ui"
MainWindow* main_window_new (void);
MainWindow* main_window_construct (GType object_type);
void main_window_set_entry_price (MainWindow* self, GtkEntry* value);
GtkEntry* main_window_get_entry_price (MainWindow* self);
void main_window_set_entry_number (MainWindow* self, GtkEntry* value);
GtkEntry* main_window_get_entry_number (MainWindow* self);
void main_window_set_textview_output (MainWindow* self, GtkTextView* value);
void main_window_set_combobox_discount (MainWindow* self, GtkComboBox* value);
void main_window_only_digit (MainWindow* self, GtkEditable* editable, gboolean allowd_dot, const gchar* text);
void main_window_entry_price_only_digit (MainWindow* self, const gchar* text, gint length, gint* position);
void main_window_entry_number_only_digit (MainWindow* self, const gchar* text, gint length, gint* position);
void main_window_calc (MainWindow* self);
GtkComboBox* main_window_get_combobox_discount (MainWindow* self);
GType discount_get_type (void) G_GNUC_CONST;
Discount* discount_factory_CreateDiscount (const gchar* rate);
gdouble discount_acceptCash (Discount* self, gdouble cash);
GtkTextView* main_window_get_textview_output (MainWindow* self);
void main_window_clear (MainWindow* self);
void main_window_on_destroy (GtkWidget* window, MainWindow* self);
static gint main_window_main (gchar** args, int args_length1);
static void main_window_finalize (GObject* obj);
static void _vala_main_window_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec);
static void _vala_main_window_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec);


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


MainWindow* main_window_construct (GType object_type) {
	MainWindow * self = NULL;
	GError * _inner_error_ = NULL;
	self = (MainWindow*) g_object_new (object_type, NULL);
	{
		GtkBuilder* _tmp0_;
		GtkBuilder* builder;
		GObject* _tmp1_ = NULL;
		GtkEntry* _tmp2_;
		GObject* _tmp3_ = NULL;
		GtkEntry* _tmp4_;
		GObject* _tmp5_ = NULL;
		GObject* _tmp6_ = NULL;
		GObject* _tmp7_ = NULL;
		GtkWindow* _tmp8_;
		GtkWindow* window;
		GtkWindow* _tmp9_;
		_tmp0_ = gtk_builder_new ();
		builder = _tmp0_;
		gtk_builder_add_from_file (builder, MAIN_WINDOW_UI_FILE, &_inner_error_);
		if (_inner_error_ != NULL) {
			_g_object_unref0 (builder);
			goto __catch0_g_error;
		}
		_tmp1_ = gtk_builder_get_object (builder, "entry_price");
		main_window_set_entry_price (self, G_TYPE_CHECK_INSTANCE_TYPE (_tmp1_, GTK_TYPE_ENTRY) ? ((GtkEntry*) _tmp1_) : NULL);
		_tmp2_ = self->priv->_entry_price;
		_vala_assert (_tmp2_ != NULL, "entry_price != null");
		_tmp3_ = gtk_builder_get_object (builder, "entry_number");
		main_window_set_entry_number (self, G_TYPE_CHECK_INSTANCE_TYPE (_tmp3_, GTK_TYPE_ENTRY) ? ((GtkEntry*) _tmp3_) : NULL);
		_tmp4_ = self->priv->_entry_number;
		_vala_assert (_tmp4_ != NULL, "entry_number != null");
		_tmp5_ = gtk_builder_get_object (builder, "textview_output");
		main_window_set_textview_output (self, G_TYPE_CHECK_INSTANCE_TYPE (_tmp5_, GTK_TYPE_TEXT_VIEW) ? ((GtkTextView*) _tmp5_) : NULL);
		_tmp6_ = gtk_builder_get_object (builder, "combobox_discount");
		main_window_set_combobox_discount (self, G_TYPE_CHECK_INSTANCE_TYPE (_tmp6_, GTK_TYPE_COMBO_BOX) ? ((GtkComboBox*) _tmp6_) : NULL);
		_tmp7_ = gtk_builder_get_object (builder, "window_main");
		_tmp8_ = _g_object_ref0 (G_TYPE_CHECK_INSTANCE_TYPE (_tmp7_, GTK_TYPE_WINDOW) ? ((GtkWindow*) _tmp7_) : NULL);
		window = _tmp8_;
		gtk_builder_connect_signals (builder, self);
		_tmp9_ = window;
		gtk_widget_show_all ((GtkWidget*) _tmp9_);
		_g_object_unref0 (window);
		_g_object_unref0 (builder);
	}
	goto __finally0;
	__catch0_g_error:
	{
		GError* e = NULL;
		FILE* _tmp10_;
		GError* _tmp11_;
		const gchar* _tmp12_;
		e = _inner_error_;
		_inner_error_ = NULL;
		_tmp10_ = stderr;
		_tmp11_ = e;
		_tmp12_ = _tmp11_->message;
		fprintf (_tmp10_, "Could not load UI: %s\n", _tmp12_);
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


MainWindow* main_window_new (void) {
	return main_window_construct (TYPE_MAIN_WINDOW);
}


static gchar string_get (const gchar* self, glong index) {
	gchar result = '\0';
	glong _tmp0_;
	gchar _tmp1_;
	g_return_val_if_fail (self != NULL, '\0');
	_tmp0_ = index;
	_tmp1_ = ((gchar*) self)[_tmp0_];
	result = _tmp1_;
	return result;
}


void main_window_only_digit (MainWindow* self, GtkEditable* editable, gboolean allowd_dot, const gchar* text) {
	const gchar* _tmp0_;
	gchar _tmp1_ = '\0';
	gchar c;
	gboolean _tmp2_ = FALSE;
	gchar _tmp3_;
	gboolean _tmp4_ = FALSE;
	gboolean _tmp9_;
	GtkEditable* _tmp10_;
	g_return_if_fail (self != NULL);
	g_return_if_fail (editable != NULL);
	g_return_if_fail (text != NULL);
	_tmp0_ = text;
	_tmp1_ = string_get (_tmp0_, (glong) 0);
	c = _tmp1_;
	_tmp3_ = c;
	_tmp4_ = g_ascii_isdigit (_tmp3_);
	if (TRUE == _tmp4_) {
		_tmp2_ = TRUE;
	} else {
		gboolean _tmp5_ = FALSE;
		gboolean _tmp6_;
		gboolean _tmp8_;
		_tmp6_ = allowd_dot;
		if (TRUE == _tmp6_) {
			gchar _tmp7_;
			_tmp7_ = c;
			_tmp5_ = '.' == _tmp7_;
		} else {
			_tmp5_ = FALSE;
		}
		_tmp8_ = _tmp5_;
		_tmp2_ = _tmp8_;
	}
	_tmp9_ = _tmp2_;
	if (_tmp9_) {
		return;
	}
	_tmp10_ = editable;
	g_signal_stop_emission_by_name (_tmp10_, "insert-text");
}


void main_window_entry_price_only_digit (MainWindow* self, const gchar* text, gint length, gint* position) {
	GtkEntry* _tmp0_;
	const gchar* _tmp1_;
	g_return_if_fail (self != NULL);
	g_return_if_fail (text != NULL);
	_tmp0_ = self->priv->_entry_price;
	_tmp1_ = text;
	main_window_only_digit (self, G_TYPE_CHECK_INSTANCE_CAST (_tmp0_, GTK_TYPE_EDITABLE, GtkEditable), TRUE, _tmp1_);
}


void main_window_entry_number_only_digit (MainWindow* self, const gchar* text, gint length, gint* position) {
	GtkEntry* _tmp0_;
	const gchar* _tmp1_;
	g_return_if_fail (self != NULL);
	g_return_if_fail (text != NULL);
	_tmp0_ = self->priv->_entry_number;
	_tmp1_ = text;
	main_window_only_digit (self, G_TYPE_CHECK_INSTANCE_CAST (_tmp0_, GTK_TYPE_EDITABLE, GtkEditable), FALSE, _tmp1_);
}


static gdouble double_parse (const gchar* str) {
	gdouble result = 0.0;
	const gchar* _tmp0_;
	gdouble _tmp1_ = 0.0;
	g_return_val_if_fail (str != NULL, 0.0);
	_tmp0_ = str;
	_tmp1_ = g_ascii_strtod (_tmp0_, NULL);
	result = _tmp1_;
	return result;
}


static gchar* double_to_string (gdouble self) {
	gchar* result = NULL;
	gchar* _tmp0_ = NULL;
	gchar* _tmp1_;
	gint _tmp1__length1;
	const gchar* _tmp2_ = NULL;
	gchar* _tmp3_;
	gchar* _tmp4_;
	_tmp0_ = g_new0 (gchar, G_ASCII_DTOSTR_BUF_SIZE);
	_tmp1_ = _tmp0_;
	_tmp1__length1 = G_ASCII_DTOSTR_BUF_SIZE;
	_tmp2_ = g_ascii_dtostr (_tmp1_, G_ASCII_DTOSTR_BUF_SIZE, self);
	_tmp3_ = g_strdup (_tmp2_);
	_tmp4_ = _tmp3_;
	_tmp1_ = (g_free (_tmp1_), NULL);
	result = _tmp4_;
	return result;
}


void main_window_calc (MainWindow* self) {
	GtkEntry* _tmp0_;
	const gchar* _tmp1_;
	const gchar* _tmp2_;
	gchar* _tmp3_;
	gchar* text;
	const gchar* _tmp4_;
	gint _tmp5_;
	gint _tmp6_;
	GtkEntry* _tmp7_;
	const gchar* _tmp8_;
	const gchar* _tmp9_;
	gchar* _tmp10_;
	const gchar* _tmp11_;
	gint _tmp12_;
	gint _tmp13_;
	GtkComboBox* _tmp14_;
	GtkTreeModel* _tmp15_;
	GtkTreeModel* _tmp16_;
	GtkListStore* _tmp17_;
	GtkListStore* list_store;
	GtkEntry* _tmp18_;
	const gchar* _tmp19_;
	const gchar* _tmp20_;
	gdouble _tmp21_ = 0.0;
	GtkEntry* _tmp22_;
	const gchar* _tmp23_;
	const gchar* _tmp24_;
	gdouble _tmp25_ = 0.0;
	gdouble cash;
	GtkTreeIter iter = {0};
	GtkComboBox* _tmp26_;
	GtkTreeIter _tmp27_ = {0};
	GValue val = {0};
	GtkListStore* _tmp28_;
	GtkTreeIter _tmp29_;
	GValue _tmp30_ = {0};
	GValue _tmp31_;
	Discount* _tmp32_ = NULL;
	Discount* discount;
	Discount* _tmp33_;
	gdouble _tmp34_;
	gdouble _tmp35_ = 0.0;
	gdouble _result_;
	GtkTextView* _tmp36_;
	GtkTextBuffer* _tmp37_;
	GtkTextBuffer* _tmp38_;
	gdouble _tmp39_;
	gchar* _tmp40_ = NULL;
	gchar* _tmp41_;
	g_return_if_fail (self != NULL);
	_tmp0_ = self->priv->_entry_price;
	_tmp1_ = gtk_entry_get_text (_tmp0_);
	_tmp2_ = _tmp1_;
	_tmp3_ = g_strdup (_tmp2_);
	text = _tmp3_;
	_tmp4_ = text;
	_tmp5_ = strlen (_tmp4_);
	_tmp6_ = _tmp5_;
	if (_tmp6_ == 0) {
		_g_free0 (text);
		return;
	}
	_tmp7_ = self->priv->_entry_number;
	_tmp8_ = gtk_entry_get_text (_tmp7_);
	_tmp9_ = _tmp8_;
	_tmp10_ = g_strdup (_tmp9_);
	_g_free0 (text);
	text = _tmp10_;
	_tmp11_ = text;
	_tmp12_ = strlen (_tmp11_);
	_tmp13_ = _tmp12_;
	if (_tmp13_ == 0) {
		_g_free0 (text);
		return;
	}
	_tmp14_ = self->priv->_combobox_discount;
	_tmp15_ = gtk_combo_box_get_model (_tmp14_);
	_tmp16_ = _tmp15_;
	_tmp17_ = _g_object_ref0 (G_TYPE_CHECK_INSTANCE_CAST (_tmp16_, GTK_TYPE_LIST_STORE, GtkListStore));
	list_store = _tmp17_;
	_tmp18_ = self->priv->_entry_price;
	_tmp19_ = gtk_entry_get_text (_tmp18_);
	_tmp20_ = _tmp19_;
	_tmp21_ = double_parse (_tmp20_);
	_tmp22_ = self->priv->_entry_number;
	_tmp23_ = gtk_entry_get_text (_tmp22_);
	_tmp24_ = _tmp23_;
	_tmp25_ = double_parse (_tmp24_);
	cash = _tmp21_ * _tmp25_;
	_tmp26_ = self->priv->_combobox_discount;
	gtk_combo_box_get_active_iter (_tmp26_, &_tmp27_);
	iter = _tmp27_;
	_tmp28_ = list_store;
	_tmp29_ = iter;
	gtk_tree_model_get_value ((GtkTreeModel*) _tmp28_, &_tmp29_, 0, &_tmp30_);
	G_IS_VALUE (&val) ? (g_value_unset (&val), NULL) : NULL;
	val = _tmp30_;
	_tmp31_ = val;
	_tmp32_ = discount_factory_CreateDiscount (g_value_get_string (&_tmp31_));
	discount = _tmp32_;
	_tmp33_ = discount;
	_tmp34_ = cash;
	_tmp35_ = discount_acceptCash (_tmp33_, _tmp34_);
	_result_ = _tmp35_;
	_tmp36_ = self->priv->_textview_output;
	_tmp37_ = gtk_text_view_get_buffer (_tmp36_);
	_tmp38_ = _tmp37_;
	_tmp39_ = _result_;
	_tmp40_ = double_to_string (_tmp39_);
	_tmp41_ = _tmp40_;
	g_object_set (_tmp38_, "text", _tmp41_, NULL);
	_g_free0 (_tmp41_);
	_g_object_unref0 (discount);
	G_IS_VALUE (&val) ? (g_value_unset (&val), NULL) : NULL;
	_g_object_unref0 (list_store);
	_g_free0 (text);
}


void main_window_clear (MainWindow* self) {
	GtkEntry* _tmp0_;
	GtkEntry* _tmp1_;
	GtkTextView* _tmp2_;
	GtkTextBuffer* _tmp3_;
	GtkTextBuffer* _tmp4_;
	g_return_if_fail (self != NULL);
	_tmp0_ = self->priv->_entry_price;
	gtk_entry_set_text (_tmp0_, "");
	_tmp1_ = self->priv->_entry_number;
	gtk_entry_set_text (_tmp1_, "");
	_tmp2_ = self->priv->_textview_output;
	_tmp3_ = gtk_text_view_get_buffer (_tmp2_);
	_tmp4_ = _tmp3_;
	g_object_set (_tmp4_, "text", "", NULL);
}


void main_window_on_destroy (GtkWidget* window, MainWindow* self) {
	g_return_if_fail (self != NULL);
	g_return_if_fail (window != NULL);
	gtk_main_quit ();
}


static gint main_window_main (gchar** args, int args_length1) {
	gint result = 0;
	MainWindow* _tmp0_;
	MainWindow* app;
	gtk_init (&args_length1, &args);
	_tmp0_ = main_window_new ();
	app = _tmp0_;
	gtk_main ();
	result = 0;
	_g_object_unref0 (app);
	return result;
}


int main (int argc, char ** argv) {
	g_type_init ();
	return main_window_main (argv, argc);
}


GtkEntry* main_window_get_entry_price (MainWindow* self) {
	GtkEntry* result;
	GtkEntry* _tmp0_;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->_entry_price;
	result = _tmp0_;
	return result;
}


void main_window_set_entry_price (MainWindow* self, GtkEntry* value) {
	GtkEntry* _tmp0_;
	GtkEntry* _tmp1_;
	g_return_if_fail (self != NULL);
	_tmp0_ = value;
	_tmp1_ = _g_object_ref0 (_tmp0_);
	_g_object_unref0 (self->priv->_entry_price);
	self->priv->_entry_price = _tmp1_;
	g_object_notify ((GObject *) self, "entry-price");
}


GtkEntry* main_window_get_entry_number (MainWindow* self) {
	GtkEntry* result;
	GtkEntry* _tmp0_;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->_entry_number;
	result = _tmp0_;
	return result;
}


void main_window_set_entry_number (MainWindow* self, GtkEntry* value) {
	GtkEntry* _tmp0_;
	GtkEntry* _tmp1_;
	g_return_if_fail (self != NULL);
	_tmp0_ = value;
	_tmp1_ = _g_object_ref0 (_tmp0_);
	_g_object_unref0 (self->priv->_entry_number);
	self->priv->_entry_number = _tmp1_;
	g_object_notify ((GObject *) self, "entry-number");
}


GtkTextView* main_window_get_textview_output (MainWindow* self) {
	GtkTextView* result;
	GtkTextView* _tmp0_;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->_textview_output;
	result = _tmp0_;
	return result;
}


void main_window_set_textview_output (MainWindow* self, GtkTextView* value) {
	GtkTextView* _tmp0_;
	GtkTextView* _tmp1_;
	g_return_if_fail (self != NULL);
	_tmp0_ = value;
	_tmp1_ = _g_object_ref0 (_tmp0_);
	_g_object_unref0 (self->priv->_textview_output);
	self->priv->_textview_output = _tmp1_;
	g_object_notify ((GObject *) self, "textview-output");
}


GtkComboBox* main_window_get_combobox_discount (MainWindow* self) {
	GtkComboBox* result;
	GtkComboBox* _tmp0_;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->_combobox_discount;
	result = _tmp0_;
	return result;
}


void main_window_set_combobox_discount (MainWindow* self, GtkComboBox* value) {
	GtkComboBox* _tmp0_;
	GtkComboBox* _tmp1_;
	g_return_if_fail (self != NULL);
	_tmp0_ = value;
	_tmp1_ = _g_object_ref0 (_tmp0_);
	_g_object_unref0 (self->priv->_combobox_discount);
	self->priv->_combobox_discount = _tmp1_;
	g_object_notify ((GObject *) self, "combobox-discount");
}


static void main_window_class_init (MainWindowClass * klass) {
	main_window_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (MainWindowPrivate));
	G_OBJECT_CLASS (klass)->get_property = _vala_main_window_get_property;
	G_OBJECT_CLASS (klass)->set_property = _vala_main_window_set_property;
	G_OBJECT_CLASS (klass)->finalize = main_window_finalize;
	g_object_class_install_property (G_OBJECT_CLASS (klass), MAIN_WINDOW_ENTRY_PRICE, g_param_spec_object ("entry-price", "entry-price", "entry-price", GTK_TYPE_ENTRY, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE));
	g_object_class_install_property (G_OBJECT_CLASS (klass), MAIN_WINDOW_ENTRY_NUMBER, g_param_spec_object ("entry-number", "entry-number", "entry-number", GTK_TYPE_ENTRY, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE));
	g_object_class_install_property (G_OBJECT_CLASS (klass), MAIN_WINDOW_TEXTVIEW_OUTPUT, g_param_spec_object ("textview-output", "textview-output", "textview-output", GTK_TYPE_TEXT_VIEW, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE));
	g_object_class_install_property (G_OBJECT_CLASS (klass), MAIN_WINDOW_COMBOBOX_DISCOUNT, g_param_spec_object ("combobox-discount", "combobox-discount", "combobox-discount", GTK_TYPE_COMBO_BOX, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE));
}


static void main_window_instance_init (MainWindow * self) {
	self->priv = MAIN_WINDOW_GET_PRIVATE (self);
}


static void main_window_finalize (GObject* obj) {
	MainWindow * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, TYPE_MAIN_WINDOW, MainWindow);
	_g_object_unref0 (self->priv->_entry_price);
	_g_object_unref0 (self->priv->_entry_number);
	_g_object_unref0 (self->priv->_textview_output);
	_g_object_unref0 (self->priv->_combobox_discount);
	G_OBJECT_CLASS (main_window_parent_class)->finalize (obj);
}


GType main_window_get_type (void) {
	static volatile gsize main_window_type_id__volatile = 0;
	if (g_once_init_enter (&main_window_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (MainWindowClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) main_window_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (MainWindow), 0, (GInstanceInitFunc) main_window_instance_init, NULL };
		GType main_window_type_id;
		main_window_type_id = g_type_register_static (G_TYPE_OBJECT, "MainWindow", &g_define_type_info, 0);
		g_once_init_leave (&main_window_type_id__volatile, main_window_type_id);
	}
	return main_window_type_id__volatile;
}


static void _vala_main_window_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec) {
	MainWindow * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (object, TYPE_MAIN_WINDOW, MainWindow);
	switch (property_id) {
		case MAIN_WINDOW_ENTRY_PRICE:
		g_value_set_object (value, main_window_get_entry_price (self));
		break;
		case MAIN_WINDOW_ENTRY_NUMBER:
		g_value_set_object (value, main_window_get_entry_number (self));
		break;
		case MAIN_WINDOW_TEXTVIEW_OUTPUT:
		g_value_set_object (value, main_window_get_textview_output (self));
		break;
		case MAIN_WINDOW_COMBOBOX_DISCOUNT:
		g_value_set_object (value, main_window_get_combobox_discount (self));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}


static void _vala_main_window_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec) {
	MainWindow * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (object, TYPE_MAIN_WINDOW, MainWindow);
	switch (property_id) {
		case MAIN_WINDOW_ENTRY_PRICE:
		main_window_set_entry_price (self, g_value_get_object (value));
		break;
		case MAIN_WINDOW_ENTRY_NUMBER:
		main_window_set_entry_number (self, g_value_get_object (value));
		break;
		case MAIN_WINDOW_TEXTVIEW_OUTPUT:
		main_window_set_textview_output (self, g_value_get_object (value));
		break;
		case MAIN_WINDOW_COMBOBOX_DISCOUNT:
		main_window_set_combobox_discount (self, g_value_get_object (value));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}



