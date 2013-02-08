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

using GLib;
using Gtk;

public class MainWindow : Object 
{

	/* 
	 * Uncomment this line when you are done testing and building a tarball
	 * or installing
	 */
	//const string UI_FILE = Config.PACKAGE_DATA_DIR + "/" + "pricecalc.ui";
	const string UI_FILE = "/home/sd/pricecalc-0.1/src/pricecalc.ui"; //"src/pricecalc.ui";

	/* ANJUTA: Widgets declaration for pricecalc.ui - DO NOT REMOVE */
	public Entry entry_price { get; set; }
	public Entry entry_number { get; set; }
	public TextView textview_output { get; set; }
	public ComboBox combobox_discount { get; set; }

	public MainWindow ()
	{

		try 
		{
			var builder = new Builder ();
			
			builder.add_from_file (UI_FILE);

			this.entry_price = builder.get_object ("entry_price") as Entry;

			assert (entry_price != null);
			
			this.entry_number = builder.get_object ("entry_number") as Entry;

			assert (entry_number != null);

			this.textview_output = builder.get_object ("textview_output")  as TextView;

			this.combobox_discount = builder.get_object ("combobox_discount")  as ComboBox;

			var window = builder.get_object ("window_main") as Window;

			builder.connect_signals (this);
			
			/* ANJUTA: Widgets initialization for pricecalc.ui - DO NOT REMOVE */
			window.show_all ();
		} 
		catch (Error e) {
			stderr.printf ("Could not load UI: %s\n", e.message);
		} 

	}

	protected void only_digit (Editable editable, bool allowd_dot, string text) {

		char c = text[0];

		if (true == c.isdigit () || true == allowd_dot && '.' == c) {
			return;
		}

		Signal.stop_emission_by_name(editable, "insert-text");
	}

	public void entry_price_only_digit (string text, int length, ref int position) {
		only_digit((Editable)this.entry_price, true, text);
	}

	public void entry_number_only_digit (string text, int length, ref int position) {
		only_digit((Editable)this.entry_number, false, text);
	}

	public void calc () {

		var text = this.entry_price.text;

		if(text.length == 0)
			return;

		text = this.entry_number.text;

		if(text.length == 0)
			return;

		var list_store = (ListStore) this.combobox_discount.model;

		var cash = double.parse (this.entry_price.text) * double.parse (this.entry_number.text);

		TreeIter iter;

		this.combobox_discount.get_active_iter (out iter);

		Value val;

		list_store.get_value (iter, 0, out val);

		var discount = DiscountFactory.CreateDiscount ((string) val);

		var result = discount.acceptCash (cash);

		this.textview_output.buffer.text = result.to_string(); 
	}

	public void clear() {
						
		this.entry_price.text = "";
		this.entry_number.text = "";
		this.textview_output.buffer.text = "";
	}

	[CCode (instance_pos = -1)]
	public void on_destroy (Widget window) 
	{
		Gtk.main_quit();
	}

	static int main (string[] args) 
	{
		Gtk.init (ref args);
		
		var app = new MainWindow ();

		Gtk.main ();
		
		return 0;
	}
}

