--������� ����� test_spawn.lua �� �������� ���� �������� 'S'

if level.present() then
	local pos = db.actor:position()
	pos.y = pos.y + 2
	pos.x = pos.x + 4

	--alife():create('zombie_plague',pos,db.actor:level_vertex_id(),db.actor:game_vertex_id())
	--alife():create('esc_vehicle_btr',pos,db.actor:level_vertex_id(),db.actor:game_vertex_id())

	ogse.send_tip("�������� ��� ����, �����, � ����� ����� �� ���� ���������!�")
end
