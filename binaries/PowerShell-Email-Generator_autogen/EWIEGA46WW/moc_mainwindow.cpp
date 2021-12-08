/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../PowerShell-Email-Generator/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    const uint offsetsAndSize[122];
    char stringdata0[1156];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 10), // "MainWindow"
QT_MOC_LITERAL(11, 13), // "add_date_edit"
QT_MOC_LITERAL(25, 0), // ""
QT_MOC_LITERAL(26, 8), // "cell_row"
QT_MOC_LITERAL(35, 8), // "cell_col"
QT_MOC_LITERAL(44, 16), // "add_status_combo"
QT_MOC_LITERAL(61, 16), // "add_day_checkBox"
QT_MOC_LITERAL(78, 19), // "add_folder_checkBox"
QT_MOC_LITERAL(98, 23), // "on_actionOpen_triggered"
QT_MOC_LITERAL(122, 23), // "on_actionSave_triggered"
QT_MOC_LITERAL(146, 24), // "on_actionClose_triggered"
QT_MOC_LITERAL(171, 45), // "on_actionGenerate_PowerShell_..."
QT_MOC_LITERAL(217, 10), // "create_XML"
QT_MOC_LITERAL(228, 22), // "tinyxml2::XMLDocument*"
QT_MOC_LITERAL(251, 28), // "on_projectNameButton_clicked"
QT_MOC_LITERAL(280, 28), // "on_projectGateButton_clicked"
QT_MOC_LITERAL(309, 24), // "on_gateDueButton_clicked"
QT_MOC_LITERAL(334, 21), // "on_taskButton_clicked"
QT_MOC_LITERAL(356, 22), // "on_ownerButton_clicked"
QT_MOC_LITERAL(379, 27), // "on_ownerEmailButton_clicked"
QT_MOC_LITERAL(407, 24), // "on_managerButton_clicked"
QT_MOC_LITERAL(432, 29), // "on_managerEmailButton_clicked"
QT_MOC_LITERAL(462, 23), // "on_statusButton_clicked"
QT_MOC_LITERAL(486, 24), // "on_dueDateButton_clicked"
QT_MOC_LITERAL(511, 25), // "on_generateButton_clicked"
QT_MOC_LITERAL(537, 20), // "create_script_header"
QT_MOC_LITERAL(558, 16), // "createMailScript"
QT_MOC_LITERAL(575, 3), // "row"
QT_MOC_LITERAL(579, 2), // "to"
QT_MOC_LITERAL(582, 2), // "cc"
QT_MOC_LITERAL(585, 3), // "bcc"
QT_MOC_LITERAL(589, 7), // "subject"
QT_MOC_LITERAL(597, 4), // "body"
QT_MOC_LITERAL(602, 13), // "attachments_1"
QT_MOC_LITERAL(616, 13), // "attachments_2"
QT_MOC_LITERAL(630, 13), // "attachments_3"
QT_MOC_LITERAL(644, 13), // "attachments_4"
QT_MOC_LITERAL(658, 13), // "attachments_5"
QT_MOC_LITERAL(672, 15), // "generate_script"
QT_MOC_LITERAL(688, 13), // "keyPressEvent"
QT_MOC_LITERAL(702, 10), // "QKeyEvent*"
QT_MOC_LITERAL(713, 5), // "event"
QT_MOC_LITERAL(719, 24), // "on_actionAbout_triggered"
QT_MOC_LITERAL(744, 14), // "status_changed"
QT_MOC_LITERAL(759, 14), // "set_date_color"
QT_MOC_LITERAL(774, 26), // "on_tableWidget_itemChanged"
QT_MOC_LITERAL(801, 17), // "QTableWidgetItem*"
QT_MOC_LITERAL(819, 4), // "item"
QT_MOC_LITERAL(824, 33), // "on_tableWidget_currentCellCha..."
QT_MOC_LITERAL(858, 10), // "currentRow"
QT_MOC_LITERAL(869, 13), // "currentColumn"
QT_MOC_LITERAL(883, 11), // "previousRow"
QT_MOC_LITERAL(895, 14), // "previousColumn"
QT_MOC_LITERAL(910, 30), // "on_selectFolderButton1_clicked"
QT_MOC_LITERAL(941, 30), // "on_selectFolderButton2_clicked"
QT_MOC_LITERAL(972, 30), // "on_selectFolderButton3_clicked"
QT_MOC_LITERAL(1003, 30), // "on_selectFolderButton4_clicked"
QT_MOC_LITERAL(1034, 30), // "on_selectFolderButton5_clicked"
QT_MOC_LITERAL(1065, 35), // "on_actionClear_Table_Data_tri..."
QT_MOC_LITERAL(1101, 20), // "on_runButton_clicked"
QT_MOC_LITERAL(1122, 33) // "on_actionClear_All_Data_trigg..."

    },
    "MainWindow\0add_date_edit\0\0cell_row\0"
    "cell_col\0add_status_combo\0add_day_checkBox\0"
    "add_folder_checkBox\0on_actionOpen_triggered\0"
    "on_actionSave_triggered\0"
    "on_actionClose_triggered\0"
    "on_actionGenerate_PowerShell_Script_triggered\0"
    "create_XML\0tinyxml2::XMLDocument*\0"
    "on_projectNameButton_clicked\0"
    "on_projectGateButton_clicked\0"
    "on_gateDueButton_clicked\0on_taskButton_clicked\0"
    "on_ownerButton_clicked\0"
    "on_ownerEmailButton_clicked\0"
    "on_managerButton_clicked\0"
    "on_managerEmailButton_clicked\0"
    "on_statusButton_clicked\0"
    "on_dueDateButton_clicked\0"
    "on_generateButton_clicked\0"
    "create_script_header\0createMailScript\0"
    "row\0to\0cc\0bcc\0subject\0body\0attachments_1\0"
    "attachments_2\0attachments_3\0attachments_4\0"
    "attachments_5\0generate_script\0"
    "keyPressEvent\0QKeyEvent*\0event\0"
    "on_actionAbout_triggered\0status_changed\0"
    "set_date_color\0on_tableWidget_itemChanged\0"
    "QTableWidgetItem*\0item\0"
    "on_tableWidget_currentCellChanged\0"
    "currentRow\0currentColumn\0previousRow\0"
    "previousColumn\0on_selectFolderButton1_clicked\0"
    "on_selectFolderButton2_clicked\0"
    "on_selectFolderButton3_clicked\0"
    "on_selectFolderButton4_clicked\0"
    "on_selectFolderButton5_clicked\0"
    "on_actionClear_Table_Data_triggered\0"
    "on_runButton_clicked\0"
    "on_actionClear_All_Data_triggered"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      48,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    2,  302,    2, 0x08,    1 /* Private */,
       5,    2,  307,    2, 0x08,    4 /* Private */,
       6,    2,  312,    2, 0x08,    7 /* Private */,
       7,    2,  317,    2, 0x08,   10 /* Private */,
       8,    0,  322,    2, 0x08,   13 /* Private */,
       9,    0,  323,    2, 0x08,   14 /* Private */,
      10,    0,  324,    2, 0x08,   15 /* Private */,
      11,    0,  325,    2, 0x08,   16 /* Private */,
      12,    0,  326,    2, 0x08,   17 /* Private */,
      14,    0,  327,    2, 0x08,   18 /* Private */,
      15,    0,  328,    2, 0x08,   19 /* Private */,
      16,    0,  329,    2, 0x08,   20 /* Private */,
      17,    0,  330,    2, 0x08,   21 /* Private */,
      18,    0,  331,    2, 0x08,   22 /* Private */,
      19,    0,  332,    2, 0x08,   23 /* Private */,
      20,    0,  333,    2, 0x08,   24 /* Private */,
      21,    0,  334,    2, 0x08,   25 /* Private */,
      22,    0,  335,    2, 0x08,   26 /* Private */,
      23,    0,  336,    2, 0x08,   27 /* Private */,
      24,    0,  337,    2, 0x08,   28 /* Private */,
      25,    0,  338,    2, 0x08,   29 /* Private */,
      26,   11,  339,    2, 0x08,   30 /* Private */,
      26,   10,  362,    2, 0x28,   42 /* Private | MethodCloned */,
      26,    9,  383,    2, 0x28,   53 /* Private | MethodCloned */,
      26,    8,  402,    2, 0x28,   63 /* Private | MethodCloned */,
      26,    7,  419,    2, 0x28,   72 /* Private | MethodCloned */,
      26,    6,  434,    2, 0x28,   80 /* Private | MethodCloned */,
      26,    5,  447,    2, 0x28,   87 /* Private | MethodCloned */,
      26,    4,  458,    2, 0x28,   93 /* Private | MethodCloned */,
      26,    3,  467,    2, 0x28,   98 /* Private | MethodCloned */,
      26,    2,  474,    2, 0x28,  102 /* Private | MethodCloned */,
      26,    1,  479,    2, 0x28,  105 /* Private | MethodCloned */,
      26,    0,  482,    2, 0x28,  107 /* Private | MethodCloned */,
      38,    0,  483,    2, 0x08,  108 /* Private */,
      39,    1,  484,    2, 0x08,  109 /* Private */,
      42,    0,  487,    2, 0x08,  111 /* Private */,
      43,    0,  488,    2, 0x08,  112 /* Private */,
      44,    0,  489,    2, 0x08,  113 /* Private */,
      45,    1,  490,    2, 0x08,  114 /* Private */,
      48,    4,  493,    2, 0x08,  116 /* Private */,
      53,    0,  502,    2, 0x08,  121 /* Private */,
      54,    0,  503,    2, 0x08,  122 /* Private */,
      55,    0,  504,    2, 0x08,  123 /* Private */,
      56,    0,  505,    2, 0x08,  124 /* Private */,
      57,    0,  506,    2, 0x08,  125 /* Private */,
      58,    0,  507,    2, 0x08,  126 /* Private */,
      59,    0,  508,    2, 0x08,  127 /* Private */,
      60,    0,  509,    2, 0x08,  128 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    3,    4,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    3,    4,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    3,    4,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    3,    4,
    QMetaType::Void,
    QMetaType::Bool,
    QMetaType::Void,
    QMetaType::Void,
    0x80000000 | 13,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::QString,
    QMetaType::QString, QMetaType::Int, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,   27,   28,   29,   30,   31,   32,   33,   34,   35,   36,   37,
    QMetaType::QString, QMetaType::Int, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,   27,   28,   29,   30,   31,   32,   33,   34,   35,   36,
    QMetaType::QString, QMetaType::Int, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,   27,   28,   29,   30,   31,   32,   33,   34,   35,
    QMetaType::QString, QMetaType::Int, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,   27,   28,   29,   30,   31,   32,   33,   34,
    QMetaType::QString, QMetaType::Int, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,   27,   28,   29,   30,   31,   32,   33,
    QMetaType::QString, QMetaType::Int, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,   27,   28,   29,   30,   31,   32,
    QMetaType::QString, QMetaType::Int, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,   27,   28,   29,   30,   31,
    QMetaType::QString, QMetaType::Int, QMetaType::QString, QMetaType::QString, QMetaType::QString,   27,   28,   29,   30,
    QMetaType::QString, QMetaType::Int, QMetaType::QString, QMetaType::QString,   27,   28,   29,
    QMetaType::QString, QMetaType::Int, QMetaType::QString,   27,   28,
    QMetaType::QString, QMetaType::Int,   27,
    QMetaType::QString,
    QMetaType::QString,
    QMetaType::Void, 0x80000000 | 40,   41,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 46,   47,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,   49,   50,   51,   52,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->add_date_edit((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->add_status_combo((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->add_day_checkBox((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: _t->add_folder_checkBox((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 4: _t->on_actionOpen_triggered(); break;
        case 5: { bool _r = _t->on_actionSave_triggered();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 6: _t->on_actionClose_triggered(); break;
        case 7: _t->on_actionGenerate_PowerShell_Script_triggered(); break;
        case 8: { tinyxml2::XMLDocument* _r = _t->create_XML();
            if (_a[0]) *reinterpret_cast< tinyxml2::XMLDocument**>(_a[0]) = std::move(_r); }  break;
        case 9: _t->on_projectNameButton_clicked(); break;
        case 10: _t->on_projectGateButton_clicked(); break;
        case 11: _t->on_gateDueButton_clicked(); break;
        case 12: _t->on_taskButton_clicked(); break;
        case 13: _t->on_ownerButton_clicked(); break;
        case 14: _t->on_ownerEmailButton_clicked(); break;
        case 15: _t->on_managerButton_clicked(); break;
        case 16: _t->on_managerEmailButton_clicked(); break;
        case 17: _t->on_statusButton_clicked(); break;
        case 18: _t->on_dueDateButton_clicked(); break;
        case 19: _t->on_generateButton_clicked(); break;
        case 20: { QString _r = _t->create_script_header();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 21: { QString _r = _t->createMailScript((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5])),(*reinterpret_cast< QString(*)>(_a[6])),(*reinterpret_cast< QString(*)>(_a[7])),(*reinterpret_cast< QString(*)>(_a[8])),(*reinterpret_cast< QString(*)>(_a[9])),(*reinterpret_cast< QString(*)>(_a[10])),(*reinterpret_cast< QString(*)>(_a[11])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 22: { QString _r = _t->createMailScript((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5])),(*reinterpret_cast< QString(*)>(_a[6])),(*reinterpret_cast< QString(*)>(_a[7])),(*reinterpret_cast< QString(*)>(_a[8])),(*reinterpret_cast< QString(*)>(_a[9])),(*reinterpret_cast< QString(*)>(_a[10])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 23: { QString _r = _t->createMailScript((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5])),(*reinterpret_cast< QString(*)>(_a[6])),(*reinterpret_cast< QString(*)>(_a[7])),(*reinterpret_cast< QString(*)>(_a[8])),(*reinterpret_cast< QString(*)>(_a[9])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 24: { QString _r = _t->createMailScript((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5])),(*reinterpret_cast< QString(*)>(_a[6])),(*reinterpret_cast< QString(*)>(_a[7])),(*reinterpret_cast< QString(*)>(_a[8])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 25: { QString _r = _t->createMailScript((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5])),(*reinterpret_cast< QString(*)>(_a[6])),(*reinterpret_cast< QString(*)>(_a[7])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 26: { QString _r = _t->createMailScript((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5])),(*reinterpret_cast< QString(*)>(_a[6])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 27: { QString _r = _t->createMailScript((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 28: { QString _r = _t->createMailScript((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 29: { QString _r = _t->createMailScript((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 30: { QString _r = _t->createMailScript((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 31: { QString _r = _t->createMailScript((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 32: { QString _r = _t->createMailScript();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 33: { QString _r = _t->generate_script();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 34: _t->keyPressEvent((*reinterpret_cast< QKeyEvent*(*)>(_a[1]))); break;
        case 35: _t->on_actionAbout_triggered(); break;
        case 36: _t->status_changed(); break;
        case 37: _t->set_date_color(); break;
        case 38: _t->on_tableWidget_itemChanged((*reinterpret_cast< QTableWidgetItem*(*)>(_a[1]))); break;
        case 39: _t->on_tableWidget_currentCellChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 40: _t->on_selectFolderButton1_clicked(); break;
        case 41: _t->on_selectFolderButton2_clicked(); break;
        case 42: _t->on_selectFolderButton3_clicked(); break;
        case 43: _t->on_selectFolderButton4_clicked(); break;
        case 44: _t->on_selectFolderButton5_clicked(); break;
        case 45: _t->on_actionClear_Table_Data_triggered(); break;
        case 46: _t->on_runButton_clicked(); break;
        case 47: _t->on_actionClear_All_Data_triggered(); break;
        default: ;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.offsetsAndSize,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_MainWindow_t
, QtPrivate::TypeAndForceComplete<MainWindow, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<tinyxml2::XMLDocument *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QKeyEvent *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QTableWidgetItem *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 48)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 48;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 48)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 48;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
