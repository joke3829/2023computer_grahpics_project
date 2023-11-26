
#include "Mesh.h"
#include "ShaderProgram.h"

bool Mesh::box_check = false;

Mesh::Mesh(std::string filename) {
	Initialize(filename);
}

Mesh::~Mesh()
{
	// ��������� ��ȯ�ض�
	glBindVertexArray(VAO);
	glDeleteBuffers(1, &EBO);
	glDeleteBuffers(3, VBO);
	glDeleteVertexArrays(1, &VAO);

	glBindVertexArray(B_VAO);
	glDeleteBuffers(1, &B_EBO);
	glDeleteBuffers(3, B_VBO);
	glDeleteVertexArrays(1, &B_VAO);
	std::cout << "Mesh ����" << '\n';
}

void Mesh::Initialize(std::string filename)
{
	if (not ReadOBJ(filename)) {
		std::cerr << "obj�� ����� ������� �ʾҽ��ϴ�" << "\n";
		return;
	}
	// ����� �����ϰ� �÷� ����

	std::random_device rd;
	std::default_random_engine dre(rd());
	std::uniform_real_distribution<float> urd_color(0.0, 1.0);

	for (int i = 0; i < vertexs.size(); ++i) {
		glm::vec3 temp_color;
		temp_color.x = urd_color(dre);
		temp_color.y = urd_color(dre);
		temp_color.z = urd_color(dre);
		colors.push_back(temp_color);
	}

	modelTrans = glm::mat4(1.0f);
	rotateMatrix = glm::mat4(1.0f);

	cur_loc = glm::vec3(0.0);
	init_pos = glm::vec3(0.0);
	cur_rot = glm::vec3(0.0);
	init_rot = glm::vec3(0.0);

	shader = ShaderProgram::getShader();
	
	glUseProgram(shader->s_program);

	glGenVertexArrays(1, &VAO);
	glGenBuffers(3, VBO);
	glGenBuffers(1, &EBO);

	glBindVertexArray(VAO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * index.size(), &index.front(), GL_STATIC_DRAW);

	int loc = glGetAttribLocation(shader->s_program, "vPos");
	// ��ǥ

	glBindBuffer(GL_ARRAY_BUFFER, VBO[0]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec3) * vertexs.size(), &vertexs.front(), GL_STATIC_DRAW);
	glVertexAttribPointer(loc, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(loc);

	loc = glGetAttribLocation(shader->s_program, "vColor");
	// �÷�
	glBindBuffer(GL_ARRAY_BUFFER, VBO[1]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec3) * colors.size(), &colors.front(), GL_STATIC_DRAW);
	glVertexAttribPointer(loc, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(loc);

	loc = glGetAttribLocation(shader->s_program, "vNormal");
	// ���� �븻
	glBindBuffer(GL_ARRAY_BUFFER, VBO[2]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec3) * vertex_normal.size(), &vertex_normal.front(), GL_STATIC_DRAW);
	glVertexAttribPointer(loc, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(loc);

	LB = glm::vec3(0.0f);
	RT = glm::vec3(0.0f);
	for (glm::vec3& pos : vertexs) {
		if (LB.x > pos.x)
			LB.x = pos.x;
		if (LB.y > pos.y)
			LB.y = pos.y;
		if (LB.z > pos.z)
			LB.z = pos.z;
		if (RT.x < pos.x)
			RT.x = pos.x;
		if (RT.y < pos.y)
			RT.y = pos.y;
		if (RT.z < pos.z)
			RT.z = pos.z;
	}
	std::vector<glm::vec3> B_pos;
	{
		B_pos.push_back(glm::vec3(LB.x, LB.y, LB.z));
		B_pos.push_back(glm::vec3(LB.x, LB.y, RT.z));
		B_pos.push_back(glm::vec3(RT.x, LB.y, RT.z));
		B_pos.push_back(glm::vec3(RT.x, LB.y, LB.z));
		B_pos.push_back(glm::vec3(LB.x, RT.y, LB.z));
		B_pos.push_back(glm::vec3(LB.x, RT.y, RT.z));
		B_pos.push_back(glm::vec3(RT.x, RT.y, RT.z));
		B_pos.push_back(glm::vec3(RT.x, RT.y, LB.z));
	}
	std::vector<glm::vec3> B_color;
	{
		for(int i = 0 ; i < 8; ++i)
			B_color.push_back(glm::vec3(0, 1, 0));
	}
	std::vector<unsigned int> B_index;
	{
		// �Ʒ�
		B_index.push_back(0);
		B_index.push_back(3);
		B_index.push_back(1);
		B_index.push_back(1);
		B_index.push_back(3);
		B_index.push_back(2);
		// ����
		B_index.push_back(0);
		B_index.push_back(1);
		B_index.push_back(4);
		B_index.push_back(1);
		B_index.push_back(5);
		B_index.push_back(4);
		// ����
		B_index.push_back(1);
		B_index.push_back(2);
		B_index.push_back(5);
		B_index.push_back(5);
		B_index.push_back(2);
		B_index.push_back(6);
		// ����
		B_index.push_back(2);
		B_index.push_back(3);
		B_index.push_back(6);
		B_index.push_back(6);
		B_index.push_back(3);
		B_index.push_back(7);
		// �ĸ�
		B_index.push_back(0);
		B_index.push_back(4);
		B_index.push_back(7);
		B_index.push_back(0);
		B_index.push_back(7);
		B_index.push_back(3);
		// ����
		B_index.push_back(5);
		B_index.push_back(6);
		B_index.push_back(4);
		B_index.push_back(4);
		B_index.push_back(6);
		B_index.push_back(7);
	}

	glGenVertexArrays(1, &B_VAO);
	glGenBuffers(3, B_VBO);
	glGenBuffers(1, &B_EBO);

	glBindVertexArray(B_VAO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, B_EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * B_index.size(), &B_index.front(), GL_STATIC_DRAW);

	loc = glGetAttribLocation(shader->s_program, "vPos");
	// ��ǥ

	glBindBuffer(GL_ARRAY_BUFFER, B_VBO[0]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec3) * B_pos.size(), &B_pos.front(), GL_STATIC_DRAW);
	glVertexAttribPointer(loc, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(loc);

	loc = glGetAttribLocation(shader->s_program, "vColor");
	// �÷�
	glBindBuffer(GL_ARRAY_BUFFER, B_VBO[1]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec3) * B_color.size(), &B_color.front(), GL_STATIC_DRAW);
	glVertexAttribPointer(loc, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(loc);

	loc = glGetAttribLocation(shader->s_program, "vNormal");
	// ���� �븻
	glBindBuffer(GL_ARRAY_BUFFER, B_VBO[2]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec3) * B_pos.size(), &B_pos.front(), GL_STATIC_DRAW);
	glVertexAttribPointer(loc, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(loc);

 }

// ����� �о� ���� true��ȯ, ������ ������ index�� ����, ���� ����
bool Mesh::ReadOBJ(std::string filename)
{
	triangle_num = 0;
	char c;
	std::string str;
	std::ifstream fin(filename);
	if (not fin) {
		std::cerr << "obj������ ã�� ���߽��ϴ�. " << "\n";
		return false;
	}
	std::vector<glm::vec3> subVn;		// �������� �븻���� �ȸ��� �� ����� ����
	std::stringstream stream;
	stream.str("");
	fin >> std::noskipws;
	while (not fin.eof()) {
		fin >> c;
		str += c;
		if (c == '\n') {
			if (str[0] == 'v' && str[1] == ' ') {
				stream.str(str);
				char novalue;
				glm::vec3 temp_vertex;
				stream >> novalue >> temp_vertex.x >> temp_vertex.y >> temp_vertex.z;
				vertexs.push_back(temp_vertex);
				stream.str("");
			}
			else if (str[0] == 'v' && str[1] == 'n') {
				stream.str(str);
				char novalue;
				glm::vec3 temp_vertex;
				stream >> novalue >> novalue >> temp_vertex.x >> temp_vertex.y >> temp_vertex.z;
				vertex_normal.push_back(temp_vertex);
				subVn.push_back(temp_vertex);
				stream.str("");
			}
			else if (str[0] == 'f' && str[1] == ' ') {
				stream.str(str);
				triangle_num++;
				char type;
				int novalue;
				int temp_index[3];
				int real_index[3];
				stream >> type >> temp_index[0] >> type >> novalue >> type >> novalue
					>> temp_index[1] >> type >> novalue >> type >> novalue
					>> temp_index[2] >> type >> novalue >> type >> novalue;
				for (int i = 0; i < 3; ++i) {
					real_index[i] = temp_index[i] - 1;
				}
				index.push_back(real_index[0]);
				index.push_back(real_index[1]);
				index.push_back(real_index[2]);
				stream.str("");
			}
			str = "";
		}
	}

	if (vertexs.size() != vertex_normal.size()) {

		struct Group {
			std::vector<unsigned int> factor;
			unsigned int normal;
		};
		str = "";

		std::vector<Group> group_set;
		fin.close();
		fin.open(filename);

		while (not fin.eof()) {
			fin >> c;
			str += c;
			if (c == '\n') {
				if (str[0] == 's') {
					Group g_temp;
					group_set.push_back(g_temp);
				}
				else if (str[0] == 'f' && str[1] == ' ') {
					stream.str(str);
					char type;
					int t_normal;
					int novalue;
					int temp_index[3];
					int real_index[3];
					stream >> type >> temp_index[0] >> type >> novalue >> type >> t_normal
						>> temp_index[1] >> type >> novalue >> type >> t_normal
						>> temp_index[2] >> type >> novalue >> type >> t_normal;
					for (int i = 0; i < 3; ++i) {
						real_index[i] = temp_index[i] - 1;
						group_set[group_set.size() - 1].factor.push_back(real_index[i]);
					}
					--t_normal;
					group_set[group_set.size() - 1].normal = t_normal;


					stream.str("");
				}
				str = "";
			}
		}

		vertex_normal.clear();
		for (int i = 0; i < vertexs.size(); ++i) {
			int num_near = 0;		// ������ �׷� ��
			glm::vec3 f_normal(0, 0, 0);		// ��ճ� ���� �븻
			for (int j = 0; j < group_set.size(); ++j) {
				for (int k = 0; k < group_set[j].factor.size(); ++k) {
					if (group_set[j].factor[k] == i) {
						num_near++;
						f_normal += subVn[group_set[j].normal];
						break;
					}
				}
			}
			f_normal.x = f_normal.x / num_near;
			f_normal.y = f_normal.y / num_near;
			f_normal.z = f_normal.z / num_near;
			vertex_normal.push_back(glm::normalize(f_normal));
		}
	}
	return true;
}

void Mesh::Render() const
{
	int loc = glGetUniformLocation(shader->s_program, "transform");
	glUniformMatrix4fv(loc, 1, GL_FALSE, glm::value_ptr(modelTrans));
	loc = glGetUniformLocation(shader->s_program, "rotateMatrix");
	glUniformMatrix4fv(loc, 1, GL_FALSE, glm::value_ptr(rotateMatrix));
	glBindVertexArray(VAO);
	glDrawElements(GL_TRIANGLES, 3 * triangle_num, GL_UNSIGNED_INT, 0);

	if (box_check) {
		glBindVertexArray(B_VAO);
		glDrawElements(GL_LINE_LOOP, 3 * 12, GL_UNSIGNED_INT, 0);
	}
}


void Mesh::init_scale(float size)
{
	glm::mat4 temp = glm::mat4(1.0f);
	modelTrans = glm::scale(temp, glm::vec3(size, size, size)) * modelTrans;
}

void Mesh::init_position(float x, float y, float z)
{
	glm::mat4 temp = glm::mat4(1.0f);
	modelTrans = glm::translate(temp, glm::vec3(x, y, z)) * modelTrans;
	init_pos = glm::vec3(x, y, z);
}

void Mesh::init_rotate(float rad, float x, float y, float z)
{
	if (x > y && x > z)
		init_rot.x += rad;
	else if (y > x && y > z)
		init_rot.y += rad;
	else if (z > x && z > y)
		init_rot.z += rad;
	glm::mat4 temp = glm::mat4(1.0f);
	modelTrans = glm::rotate(temp, glm::radians(rad), glm::vec3(x, y, z)) * modelTrans;
	temp = glm::mat4(1.0f);
	rotateMatrix = glm::rotate(temp, glm::radians(rad), glm::vec3(x, y, z)) * rotateMatrix;
}

void Mesh::setLoc(glm::vec3 new_loc)
{
	glm::mat4 temp(1.0f);
	modelTrans = glm::translate(temp, -cur_loc) * modelTrans; temp = glm::mat4(1.0f);
	cur_loc = new_loc;
	modelTrans = glm::translate(temp, cur_loc) * modelTrans;
}

void Mesh::setRot(glm::vec2 new_rot)
{
	glm::mat4 temp(1.0f);

	modelTrans = glm::translate(temp, -cur_loc) * modelTrans; temp = glm::mat4(1.0f);

	modelTrans = glm::rotate(temp, glm::radians(-(360 - cur_rot.x)), glm::vec3(0, 1, 0)) * modelTrans; temp = glm::mat4(1.0f);

	rotateMatrix = glm::rotate(temp, glm::radians(-(360 - cur_rot.x)), glm::vec3(0, 1, 0)) * rotateMatrix; temp = glm::mat4(1.0f);

	modelTrans = glm::rotate(temp, glm::radians(-cur_rot.y), glm::vec3(0, 0, 1)) * modelTrans; temp = glm::mat4(1.0f);

	rotateMatrix = glm::rotate(temp, glm::radians(-cur_rot.y), glm::vec3(0, 0, 1)) * rotateMatrix; temp = glm::mat4(1.0f);

	cur_rot = new_rot;

	modelTrans = glm::rotate(temp, glm::radians(cur_rot.y), glm::vec3(0, 0, 1)) * modelTrans; temp = glm::mat4(1.0f);

	rotateMatrix = glm::rotate(temp, glm::radians(cur_rot.y), glm::vec3(0, 0, 1)) * rotateMatrix; temp = glm::mat4(1.0f);

	modelTrans = glm::rotate(temp, glm::radians((360 - cur_rot.x)), glm::vec3(0, 1, 0)) * modelTrans; temp = glm::mat4(1.0f);

	rotateMatrix = glm::rotate(temp, glm::radians((360 - cur_rot.x)), glm::vec3(0, 1, 0)) * rotateMatrix; temp = glm::mat4(1.0f);

	modelTrans = glm::translate(temp, cur_loc) * modelTrans; temp = glm::mat4(1.0f);
}