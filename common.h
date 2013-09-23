#ifndef COMMON_H
#define COMMON_H

#include <wx/dynarray.h>
#include <wx/string.h>
#include <wx/arrstr.h>

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
	bool		enabled;/**< ��������������� �� ��������� � PP-050/DD-500 */
	wxString	strip_value;/**< ������� ����������, ��� ��� �������� ����� �������� ������� DNP*/
	wxString	pattern;/**< ��� ����������� ����� � ���� ���������� */
	wxString	pnp_name;/**< ��� ���������� � PP-050/DD-500 */
	wxString	pnp_package;/**< ��� ������� � PP-050 */
	wxString	pnp_footprint;/**< ��� ��������� � DD-500 */
	double		pnp_location_x;/**< ���������� ������ ���������� � PP-050/DD-500 */
	double		pnp_location_y;/**< ���������� ������ ���������� � PP-050/DD-500 */
	double		pnp_angle;/**< ���� �������� ���������� � PP-050/DD-500 */
	bool		pnp_enabled;/**< ��������������� �� ��������� � PP-050/DD-500 */
	size_t		pnp_subpcb_index;/**< � ������ ����� ����� ��������� */
	t_component_descr() :
		cad_location_x(0), cad_location_y(0), cad_angle(0), enabled(true),
		pnp_location_x(0), pnp_location_y(0), pnp_angle(0), pnp_enabled(true),
		pnp_subpcb_index(0) {}
};

struct t_component_type_descr {
	wxString	name;/**< �������������, ����������� �� ���� ��� � �������� � PCAD/Altium */
	wxString	pattern;/**< ��� ����������� ����� � ���� ���������� */
	wxString	pnp_name;/**< ��� ���������� � PP-050/DD-500 */
	double		value;/**< ����������� �������� ��� ����������/�������/etc. */
	wxString	unit;/**< ����������� ������������ �������� */
	wxString	value_postfix;/**< ���������� �������� (�������� ������� ������) */
	size_t		comp_count;/**< ���������� ����������� ����� ���� �� ����� */
	bool		enabled;/**< ��������������� �� ��������� � PP-050/DD-500 */
	bool		is_new;/**< ��� �� ���� ��������� � ���� ���������� */
	t_component_type_descr() : value(0), comp_count(1), enabled(true), is_new(true) {}
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

#define FID_MARK_USE_IGNORE		0
#define FID_MARK_USE_FM1		1
#define FID_MARK_USE_FM2		2
#define FID_MARK_USE_FM3		3
#define FID_MARK_USE_LOCAL		4

struct t_fid_mark_descr {
	int		component_index;/**< ������ �������� ����� � ������ ����������� */
	int		usage_type;/**< ��� ������������ */
	int		usage_as_global;/**< ���������� ����� (��� ���� ������) */
	wxArrayString	local_for_comps;/**< ������ �����������, � �������� ������������ ���� ��������� ����� (����� ";") */
	t_fid_mark_descr() :
		component_index(0), usage_type(FID_MARK_USE_IGNORE), usage_as_global(FID_MARK_USE_IGNORE) {}
};

struct t_xml_node_ptrs {
	wxXmlNode *parent;
	wxXmlNode *last_child;
	t_xml_node_ptrs() : parent(NULL), last_child(NULL) {}
};

WX_DECLARE_OBJARRAY(struct t_component_descr, tComponentDescr);
WX_DEFINE_SORTED_ARRAY(struct t_component_type_descr *, tComponentTypeDescr);
WX_DEFINE_SORTED_ARRAY(struct t_pattern_descr *, tPatternDescr);
WX_DEFINE_SORTED_ARRAY(struct t_fid_mark_descr *, tFidMarkDescr);

struct t_subpcb_descr {
	wxString	subpcb_name; /**< ��� ����� */
	double		ref_point1_x;/**< ���������� ���� ����� */
	double		ref_point1_y;/**< ���������� ���� ����� */
	double		ref_point2_x;/**< ���������� ���� ����� */
	double		ref_point2_y;/**< ���������� ���� ����� */
	double		size_x;  /**< ������ ����� */
	double		size_y;  /**< ������ ����� */
	double		offset_x;/**< �������� ����� */
	double		offset_y;/**< �������� ����� */
	bool		enabled; /**< �� �������� ��� ����� */
	t_subpcb_descr() : ref_point1_x(0), ref_point1_y(0), ref_point2_x(0), ref_point2_y(0),
		size_x(0), size_y(0), offset_x(0), offset_y(0),
		enabled(true) {}
};
WX_DECLARE_OBJARRAY(struct t_subpcb_descr, tSubPcbs);
struct t_board_descr {
	wxString	project_name;/**< ��� ������� (���� �� ����������) */
	wxString	filename;    /**< ��� �����, ������������������ �� CAD */
	wxString	fullfilename;/**< ��� �����, ������������������ �� CAD */
	double		height;  /**< ������� ����� */
	int		angle;  /**< ����, ��� ������� ����� ����������� � ������ (0=0, 1=90, 2=180, 3=270) */
	double		size_x;  /**< ������ ������ ����� */
	double		size_y;  /**< ������ ������ ����� */
	double		offset_x;/**< ���������� �������� ����� */
	double		offset_y;/**< ���������� �������� ����� */
	bool		apply_offset;/**< ���������� ����������� ��� �������� �� offset - ���� ����������� ������� */
	tSubPcbs	pcbs; /**< �������� ���� �� ����� */
	t_board_descr() : height(1.6), angle(0),
		size_x(0), size_y(0), offset_x(0), offset_y(0),
		apply_offset(false) {}
};

int CmpCompTypeFunc(t_component_type_descr *a_arg1, t_component_type_descr *a_arg2);
int CmpPatternFunc(t_pattern_descr *a_arg1, t_pattern_descr *a_arg2);
int CmpFidMarkFunc(t_fid_mark_descr *a_arg1, t_fid_mark_descr *a_arg2);

#endif // COMMON_H
