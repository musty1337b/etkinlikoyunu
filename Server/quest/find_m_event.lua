quest find_m_event begin
	state start begin
		when 79510.use with pc.count_item(79510) >= 27 begin
			pc.remove_item(79510, 27)
			pc.give_item2(79511)
		end
	end
end
