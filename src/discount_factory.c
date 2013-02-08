/* discount_factory.c generated by valac 0.18.1, the Vala compiler
 * generated from discount_factory.vala, do not modify */


#include <glib.h>
#include <glib-object.h>
#include <stdlib.h>
#include <string.h>
#include <float.h>
#include <math.h>


#define TYPE_DISCOUNT_FACTORY (discount_factory_get_type ())
#define DISCOUNT_FACTORY(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_DISCOUNT_FACTORY, DiscountFactory))
#define DISCOUNT_FACTORY_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_DISCOUNT_FACTORY, DiscountFactoryClass))
#define IS_DISCOUNT_FACTORY(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_DISCOUNT_FACTORY))
#define IS_DISCOUNT_FACTORY_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_DISCOUNT_FACTORY))
#define DISCOUNT_FACTORY_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_DISCOUNT_FACTORY, DiscountFactoryClass))

typedef struct _DiscountFactory DiscountFactory;
typedef struct _DiscountFactoryClass DiscountFactoryClass;
typedef struct _DiscountFactoryPrivate DiscountFactoryPrivate;

#define TYPE_DISCOUNT (discount_get_type ())
#define DISCOUNT(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_DISCOUNT, Discount))
#define DISCOUNT_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_DISCOUNT, DiscountClass))
#define IS_DISCOUNT(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_DISCOUNT))
#define IS_DISCOUNT_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_DISCOUNT))
#define DISCOUNT_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_DISCOUNT, DiscountClass))

typedef struct _Discount Discount;
typedef struct _DiscountClass DiscountClass;

#define TYPE_DISCOUNT_RATE (discount_rate_get_type ())
#define DISCOUNT_RATE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_DISCOUNT_RATE, DiscountRate))
#define DISCOUNT_RATE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_DISCOUNT_RATE, DiscountRateClass))
#define IS_DISCOUNT_RATE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_DISCOUNT_RATE))
#define IS_DISCOUNT_RATE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_DISCOUNT_RATE))
#define DISCOUNT_RATE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_DISCOUNT_RATE, DiscountRateClass))

typedef struct _DiscountRate DiscountRate;
typedef struct _DiscountRateClass DiscountRateClass;

struct _DiscountFactory {
	GObject parent_instance;
	DiscountFactoryPrivate * priv;
};

struct _DiscountFactoryClass {
	GObjectClass parent_class;
};


static gpointer discount_factory_parent_class = NULL;

GType discount_factory_get_type (void) G_GNUC_CONST;
enum  {
	DISCOUNT_FACTORY_DUMMY_PROPERTY
};
GType discount_get_type (void) G_GNUC_CONST;
Discount* discount_factory_CreateDiscount (const gchar* rate);
DiscountRate* discount_rate_new (gdouble rate);
DiscountRate* discount_rate_construct (GType object_type, gdouble rate);
GType discount_rate_get_type (void) G_GNUC_CONST;
DiscountFactory* discount_factory_new (void);
DiscountFactory* discount_factory_construct (GType object_type);


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


Discount* discount_factory_CreateDiscount (const gchar* rate) {
	Discount* result = NULL;
	const gchar* _tmp0_;
	gdouble _tmp1_ = 0.0;
	DiscountRate* _tmp2_;
	g_return_val_if_fail (rate != NULL, NULL);
	_tmp0_ = rate;
	_tmp1_ = double_parse (_tmp0_);
	_tmp2_ = discount_rate_new (_tmp1_);
	result = (Discount*) _tmp2_;
	return result;
}


DiscountFactory* discount_factory_construct (GType object_type) {
	DiscountFactory * self = NULL;
	self = (DiscountFactory*) g_object_new (object_type, NULL);
	return self;
}


DiscountFactory* discount_factory_new (void) {
	return discount_factory_construct (TYPE_DISCOUNT_FACTORY);
}


static void discount_factory_class_init (DiscountFactoryClass * klass) {
	discount_factory_parent_class = g_type_class_peek_parent (klass);
}


static void discount_factory_instance_init (DiscountFactory * self) {
}


GType discount_factory_get_type (void) {
	static volatile gsize discount_factory_type_id__volatile = 0;
	if (g_once_init_enter (&discount_factory_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (DiscountFactoryClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) discount_factory_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (DiscountFactory), 0, (GInstanceInitFunc) discount_factory_instance_init, NULL };
		GType discount_factory_type_id;
		discount_factory_type_id = g_type_register_static (G_TYPE_OBJECT, "DiscountFactory", &g_define_type_info, 0);
		g_once_init_leave (&discount_factory_type_id__volatile, discount_factory_type_id);
	}
	return discount_factory_type_id__volatile;
}



