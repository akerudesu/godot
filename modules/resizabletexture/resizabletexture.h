#ifndef RESIZABLETEXTURE_H
#define RESIZABLETEXTURE_H

#include "scene/resources/texture.h"

class ResizableTexture : public Texture {
	GDCLASS(ResizableTexture, Texture)

private:
	RID proxy;
	Ref<Texture> base;
	int w, h;

protected:
	static void _bind_methods();

public:
	void set_base(const Ref<Texture> &p_texture);
	Ref<Texture> get_base() const;

	virtual int get_width() const;
	virtual int get_height() const;
	virtual RID get_rid() const;

	virtual void set_width(int p_width);
	virtual void set_height(int p_height);

	virtual bool has_alpha() const;

	virtual void set_flags(uint32_t p_flags);
	virtual uint32_t get_flags() const;

	ResizableTexture();
	~ResizableTexture();
};

#endif
