create table user_info
	(id			varchar(12), 
	 pswd		varchar(10), 
	 role		varchar(15),
	 date		varchar(15),
	 primary key (id)
	);
	
create table falltypus_info
	(id				varchar(12),
	 falltypus 		varchar(10),
	 name 			varchar(20),
	 condit_case	varchar(15),
	 primary key (id)
	);
	

create table admin_info
	(id		varchar(12), 
	 name	varchar(10), 
	 sex	varchar(2),
	 age	varchar(6),
	 phone	varchar(11),
	 primary key (id),
	 foreign key (id) references user_info(id)
	);

create table caseTmie_info
	(admin_id		varchar(12),
	 case_id		varchar(12),
	 limit_time		varchar(15),
	 primary key (admin_id, case_id),
	 foreign key (admin_id) references admin_info(id),
	 foreign key (case_id) references falltypus_info(id)
	);

