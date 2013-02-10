/* discount.c generated by valac 0.18.1, the Vala compiler
 * generated from discount.vala, do not modify */


#include <glib.h>
#include <glib-object.h>
#include <float.h>
#include <math.h>


#define TYPE_DISCOUNT (discount_get_type ())
#define DISCOUNT(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_DISCOUNT, Discount))
#define DISCOUNT_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_DISCOUNT, DiscountClass))
#define IS_DISCOUNT(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_DISCOUNT))
#define IS_DISCOUNT_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_DISCOUNT))
#define DISCOUNT_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_DISCOUNT, DiscountClass))

typedef struct _Discount Discount;
typedef struct _DiscountClass DiscountClass;
typedef struct _DiscountPrivate DiscountPrivate;

#define TYPE_DISCOUNT_RATE (discount_rate_get_type ())
#define DISCOUNT_RATE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_DISCOUNT_RATE, DiscountRate))
#define DISCOUNT_RATE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_DISCOUNT_RATE, DiscountRateClass))
#define IS_DISCOUNT_RATE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_DISCOUNT_RATE))
#define IS_DISCOUNT_RATE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_DISCOUNT_RATE))
#define DISCOUNT_RATE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_DISCOUNT_RATE, DiscountRateClass))

typedef struct _DiscountRate DiscountRate;
typedef struct _DiscountRateClass DiscountRateClass;
typedef struct _DiscountRatePrivate DiscountRatePrivate;

struct _Discount {
	GObject parent_instance;
	DiscountPrivate * priv;
};

struct _DiscountClass {
	GObjectClass parent_class;
	gdouble (*acceptCash) (Discount* self, gdouble cash);
};

struct _DiscountRate {
	Discount parent_instance;
	DiscountRatePrivate * priv;
};

struct _DiscountRateClass {
	DiscountClass parent_class;
};

struct _DiscountRatePrivate {
	gdouble _rate;
};


static gpointer discount_parent_class = NULL;
static gpointer discount_rate_parent_class = NULL;

GType discount_get_type (void) G_GNUC_CONST;
enum  {
	DISCOUNT_DUMMY_PROPERTY
};
gdouble discount_acceptCash (Discount* self, gdouble cash);
static gdouble discount_real_acceptCash (Discount* self, gdouble cash);
Discount* discount_construct (GType object_type);
GType discount_rate_get_type (void) G_GNUC_CONST;
#define DISCOUNT_RATE_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), TYPE_DISCOUNT_RATE, DiscountRatePrivate))
enum  {
	DISCOUNT_RATE_DUMMY_PROPERTY,
	DISCOUNT_RATE_RATE
};
DiscountRate* discount_rate_new (gdouble rate);
DiscountRate* discount_rate_construct (GType object_type, gdouble rate);
void discount_rate_set_rate (DiscountRate* self, gdouble value);
static gdouble discount_rate_real_acceptCash (Discount* base, gdouble cash);
gdouble discount_rate_get_rate (DiscountRate* self);
static void discount_rate_finalize (GObject* obj);
static void _vala_discount_rate_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec);
static void _vala_discount_rate_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec);


static gdouble discount_real_acceptCash (Discount* self, gdouble cash) {
	g_critical ("Type `%s' does not implement abstract method `discount_acceptCash'", g_type_name (G_TYPE_FROM_INSTANCE (self)));
	return 0.0;
}


gdouble discount_acceptCash (Discount* self, gdouble cash) {
	g_return_val_if_fail (self != NULL, 0.0);
	return DISCOUNT_GET_CLASS (self)->acceptCash (self, cash);
}


Discount* discount_construct (GType object_type) {
	Discount * self = NULL;
	self = (Discount*) g_object_new (object_type, NULL);
	return self;
}


static void discount_class_init (DiscountClass * klass) {
	discount_parent_class = g_type_class_peek_parent (klass);
	DISCOUNT_CLASS (klass)->acceptCash = discount_real_acceptCash;
}


static void discount_instance_init (Discount * self) {
}


GType discount_get_type (void) {
	static volatile gsize discount_type_id__volatile = 0;
	if (g_once_init_enter (&discount_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (DiscountClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) discount_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (Discount), 0, (GInstanceInitFunc) discount_instance_init, NULL };
		GType discount_type_id;
		discount_type_id = g_type_register_static (G_TYPE_OBJECT, "Discount", &g_define_type_info, G_TYPE_FLAG_ABSTRACT);
		g_once_init_leave (&discount_type_id__volatile, discount_type_id);
	}
	return discount_type_id__volatile;
}


DiscountRate* discount_rate_construct (GType object_type, gdouble rate) {
	DiscountRate * self = NULL;
	gdouble _tmp0_;
	gdouble _tmp1_;
	gdouble _tmp2_;
	_tmp0_ = rate;
	_tmp1_ = _tmp0_;
	g_return_val_if_fail ((0.00 < _tmp1_) && (_tmp1_ <= 100.00), NULL);
	self = (DiscountRate*) discount_construct (object_type);
	_tmp2_ = rate;
	discount_rate_set_rate (self, _tmp2_);
	return self;
}


DiscountRate* discount_rate_new (gdouble rate) {
	return discount_rate_construct (TYPE_DISCOUNT_RATE, rate);
}


static gdouble discount_rate_real_acceptCash (Discount* base, gdouble cash) {
	DiscountRate * self;
	gdouble result = 0.0;
	gdouble _tmp0_;
	gdouble _tmp1_;
	self = (DiscountRate*) base;
	_tmp0_ = cash;
	_tmp1_ = self->priv->_rate;
	result = (_tmp0_ * _tmp1_) / 100;
	return result;
}


gdouble discount_rate_get_rate (DiscountRate* self) {
	gdouble result;
	gdouble _tmp0_;
	g_return_val_if_fail (self != NULL, 0.0);
	_tmp0_ = self->priv->_rate;
	result = _tmp0_;
	return result;
}


void discount_rate_set_rate (DiscountRate* self, gdouble value) {
	gdouble _tmp0_;
	g_return_if_fail (self != NULL);
	_tmp0_ = value;
	self->priv->_rate = _tmp0_;
	g_object_notify ((GObject *) self, "rate");
}


static void discount_rate_class_init (DiscountRateClass * klass) {
	discount_rate_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (DiscountRatePrivate));
	DISCOUNT_CLASS (klass)->acceptCash = discount_rate_real_acceptCash;
	G_OBJECT_CLASS (klass)->get_property = _vala_discount_rate_get_property;
	G_OBJECT_CLASS (klass)->set_property = _vala_discount_rate_set_property;
	G_OBJECT_CLASS (klass)->finalize = discount_rate_finalize;
	g_object_class_install_property (G_OBJECT_CLASS (klass), DISCOUNT_RATE_RATE, g_param_spec_double ("rate", "rate", "rate", -G_MAXDOUBLE, G_MAXDOUBLE, 0.0, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE));
}


static void discount_rate_instance_init (DiscountRate * self) {
	self->priv = DISCOUNT_RATE_GET_PRIVATE (self);
}


static void discount_rate_finalize (GObject* obj) {
	DiscountRate * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, TYPE_DISCOUNT_RATE, DiscountRate);
	G_OBJECT_CLASS (discount_rate_parent_class)->finalize (obj);
}


GType discount_rate_get_type (void) {
	static volatile gsize discount_rate_type_id__volatile = 0;
	if (g_once_init_enter (&discount_rate_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (DiscountRateClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) discount_rate_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (DiscountRate), 0, (GInstanceInitFunc) discount_rate_instance_init, NULL };
		GType discount_rate_type_id;
		discount_rate_type_id = g_type_register_static (TYPE_DISCOUNT, "DiscountRate", &g_define_type_info, 0);
		g_once_init_leave (&discount_rate_type_id__volatile, discount_rate_type_id);
	}
	return discount_rate_type_id__volatile;
}


static void _vala_discount_rate_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec) {
	DiscountRate * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (object, TYPE_DISCOUNT_RATE, DiscountRate);
	switch (property_id) {
		case DISCOUNT_RATE_RATE:
		g_value_set_double (value, discount_rate_get_rate (self));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}


static void _vala_discount_rate_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec) {
	DiscountRate * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (object, TYPE_DISCOUNT_RATE, DiscountRate);
	switch (property_id) {
		case DISCOUNT_RATE_RATE:
		discount_rate_set_rate (self, g_value_get_double (value));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}



