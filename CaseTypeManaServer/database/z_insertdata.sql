delete from caseTmie_info;
delete from admin_info;
delete from falltypus_info;
delete from user_info;

insert into user_info values ('Ad-101', '123456', '管理员', '2019-04-26');
insert into falltypus_info values ('Case-101', '部件', '路灯', '灯管损坏');
insert into admin_info values ('Ad-101', '小明', '男', '20', '15536001624');
insert into caseTmie_info values ('Ad-101', 'Case-101', '2天');