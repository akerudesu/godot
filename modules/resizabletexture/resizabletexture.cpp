#include "resizabletexture.h"

void ResizableTexture::set_base(const Ref<Texture> &p_texture) {

	base = p_texture;
	if (base.is_valid()) {
		VS::get_singleton()->texture_set_proxy(proxy, base->get_rid());
	} else {
		VS::get_singleton()->texture_set_proxy(proxy, RID());
	}

	w = base->get_width();
	h = base->get_height();
}

Ref<Texture> ResizableTexture::get_base() const {

	return base;
}

int ResizableTexture::get_width() const {

	return w;
}

int ResizableTexture::get_height() const {

	return h;
}

RID ResizableTexture::get_rid() const {

	return proxy;
}

void ResizableTexture::set_width(int p_width) {

	w = p_width;
}
void ResizableTexture::set_height(int p_height) {

	h = p_height;
}

bool ResizableTexture::has_alpha() const {

	if (base.is_valid())
		return base->has_alpha();
	return false;
}

void ResizableTexture::set_flags(uint32_t p_flags) {
}

uint32_t ResizableTexture::get_flags() const {

	if (base.is_valid())
		return base->get_flags();
	return 0;
}

ResizableTexture::ResizableTexture() {

	proxy = VS::get_singleton()->texture_create();
}

ResizableTexture::~ResizableTexture() {

	VS::get_singleton()->free(proxy);
}

void ResizableTexture::_bind_methods() {

	ClassDB::bind_method(D_METHOD("set_base", "base"), &ResizableTexture::set_base);
	ClassDB::bind_method(D_METHOD("get_base"), &ResizableTexture::get_base);

	ClassDB::bind_method(D_METHOD("set_width", "width"), &ResizableTexture::set_width);
	ClassDB::bind_method(D_METHOD("set_height", "height"), &ResizableTexture::set_height);

	ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "base", PROPERTY_HINT_RESOURCE_TYPE, "Texture"), "set_base", "get_base");

	ADD_PROPERTY(PropertyInfo(Variant::INT, "width", PROPERTY_HINT_RANGE, "1,16384"), "set_width", "get_width");
	ADD_PROPERTY(PropertyInfo(Variant::INT, "height", PROPERTY_HINT_RANGE, "1,16384"), "set_height", "get_height");
}
