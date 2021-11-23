export module SimpleTextEditor;

export class SimpleTextEditor final
{
public:
	static SimpleTextEditor& GetInstance()
	{
		static SimpleTextEditor* Instance = new SimpleTextEditor();
		return *Instance;
	}

private:
	SimpleTextEditor() = default;

	SimpleTextEditor(const SimpleTextEditor&) = delete;
	SimpleTextEditor& operator=(const SimpleTextEditor&) = delete;
	SimpleTextEditor(SimpleTextEditor&&) = delete;
	SimpleTextEditor& operator=(SimpleTextEditor&&) = delete;
};

