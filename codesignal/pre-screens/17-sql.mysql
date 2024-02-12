CREATE PROCEDURE solution()
BEGIN
	create table seats_updated as select * from seats;
	set @requests_size = 0;
	set @i = 1;
	set @current_request = 0;
	set @current_seat_no = 0;
	set @current_person_id = 0;
	set @current_status = 0;
	set @current_seat_person_id = 0;
	select count(*) from requests into @requests_size;
	while @i <= @requests_size do
		select request from (select request, request_id from requests where request_id = @i) as sub_requests into @current_request;
		select seat_no from (select seat_no, request_id from requests where request_id = @i) as sub_requests into @current_seat_no;
		select person_id from (select person_id, request_id from requests where request_id = @i) as sub_requests into @current_person_id;
		select `status` from seats_updated where seat_no = @current_seat_no into @current_status;
		select person_id from seats_updated where seat_no = @current_seat_no into @current_seat_person_id;
		if @current_seat_person_id = 0 then
			update seats_updated set `status` = @current_request, person_id = @current_person_id where seat_no = @current_seat_no;
		elseif @current_seat_person_id = @current_person_id and @current_request > @current_status then
			update seats_updated set `status` = @current_request where seat_no = @current_seat_no;
		end if;
		set @i = @i + 1;
	end while;
	select * from seats_updated;
	drop table seats_updated;
END