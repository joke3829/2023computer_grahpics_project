//============================================================
// CharacterBase.h
// ĳ���Ͱ� �ߺ����� ������ ������ �����ϴ� ��� Ŭ����
// ��ӽ��� ����Ѵ�
//============================================================


class CharacterBase {
public:
	CharacterBase();
	CharacterBase(float, float, float, float, float);				// �ʱ�ȭ
	virtual ~CharacterBase();
	void Update_HP(float);				// ü�� ���� ��� ATK�� �޾ƿͼ� ���
	bool Death_check();					// ü���� 0���ϸ� true ��ȯ
protected:
	float HP;			// ü��
	float MAXHP;		// �ִ� ü��
	float speed;		// �̵� �ӵ�
	float DEF;			// ����
	float ATK;			// �÷��̾��� ��� ���� �� ������ ���ݷ��� �޾ƿ´�.
private:
};