#ifndef COMMON_H
#define COMMON_H

#include <wx/dynarray.h>
#include <wx/string.h>

class wxXmlNode;

struct t_component_descr {
///�������� ������
	wxString	designator;/**< ����������� ���������� */
	wxString	cad_name;/**< ��� ���������� � PCAD/Altium */
	wxString	cad_pattern;/**< ��� ����������� ����� � PCAD/Altium */
	wxString	cad_value;/**< ������� ����������, ��� ��� �������� */
	wxString	full_name;/**< �������������, ����������� �� ���� ��� � �������� */
	wxString	layer;/**< ����, � ������� ��������� ��������� */
	double		cad_location_x;/**< ���������� �������� ����� ���������� � PCAD/Altium */
	double		cad_location_y;/**< ���������� �������� ����� ���������� � PCAD/Altium */
	double		cad_angle;/**< ���� �������� ���������� � PCAD/Altium */
///������������ ��������
	wxString	pattern;/**< ��� ����������� ����� � ���� ���������� */
	wxString	pnp_name;/**< ��� ���������� � PP-050/DD-500 */
	wxString	pnp_package;/**< ��� ������� � PP-050 */
	wxString	pnp_footprint;/**< ��� ��������� � DD-500 */
	double		pnp_location_x;/**< ���������� ������ ���������� � PP-050/DD-500 */
	double		pnp_location_y;/**< ���������� ������ ���������� � PP-050/DD-500 */
	double		pnp_angle;/**< ���� �������� ���������� � PP-050/DD-500 */
	bool		enabled;/**< ��������������� �� ��������� � PP-050/DD-500 */
        t_component_descr() :
        	cad_location_x(0), cad_location_y(0), cad_angle(0),
        	pnp_location_x(0), pnp_location_y(0), pnp_angle(0),
		enabled(true) {}
};

struct t_component_type_descr {
	wxString	name;/**< �������������, ����������� �� ���� ��� � �������� � PCAD/Altium */
	wxString	pattern;/**< ��� ����������� ����� � ���� ���������� */
	wxString	pnp_name;/**< ��� ���������� � PP-050/DD-500 */
	size_t		comp_count;/**< ���������� ����������� ����� ���� �� ����� */
	bool		enabled;/**< ��������������� �� ��������� � PP-050/DD-500 */
	bool		is_new;/**< ��� �� ���� ��������� � ���� ���������� */
        t_component_type_descr() : comp_count(1), enabled(true), is_new(true) {}
};

struct t_pattern_descr {
	wxString	pattern;/**< ��� ����������� ����� � ���� ���������� */
	wxString	pnp_package;/**< ��� ������� � PP-050 */
	wxString	pnp_footprint;/**< ��� ��������� � DD-500 */
	double		offset_x;/**< �������� ������ ���������� �� �������� ����� */
	double		offset_y;/**< �������� ������ ���������� �� �������� ����� */
	double		angle;/**< ���� �������� ���������� � ���� PCAD/Altium ������������ PP-050/DD-500 */
	size_t		comp_count;/**< ���������� ����������� � ����� �������� �� ����� */
	bool		enabled;/**< ��������������� �� ��������� � ����� �������� � PP-050/DD-500 */
	bool		is_new;/**< ��� �� ���� ������ � ���� ���������� */
        t_pattern_descr() : offset_x(0), offset_y(0), angle(0),
        	comp_count(1), enabled(true), is_new(true) {}
};

struct t_xml_node_ptrs {
	wxXmlNode *parent;
	wxXmlNode *last_child;
	int elemets_count;
};

WX_DECLARE_OBJARRAY(struct t_component_descr, tComponentDescr);
WX_DEFINE_SORTED_ARRAY(struct t_component_type_descr *, tComponentTypeDescr);
WX_DEFINE_SORTED_ARRAY(struct t_pattern_descr *, tPatternDescr);

int CmpCompTypeFunc(t_component_type_descr *a_arg1, t_component_type_descr *a_arg2);
int CmpPatternFunc(t_pattern_descr *a_arg1, t_pattern_descr *a_arg2);

#endif // COMMON_H
