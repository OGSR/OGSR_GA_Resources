--читовый спавн test_spawn.lua из главного меню нажатием 'S'

if level.present() then
	local pos = db.actor:position()
	pos.y = pos.y + 2
	pos.x = pos.x + 4

	--alife():create('zombie_plague',pos,db.actor:level_vertex_id(),db.actor:game_vertex_id())
	--alife():create('esc_vehicle_btr',pos,db.actor:level_vertex_id(),db.actor:game_vertex_id())

	ogse.send_tip("Ђ—частье дл€ всех, даром, и пусть никто не уйдЄт обиженный!ї")
end
