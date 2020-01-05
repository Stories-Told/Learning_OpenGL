# Learning_OpenGL
Three triangles drawn and colored


/* Vertex shaders and fragment shaders if not using a header file that reads from other files (All fragments run from one
vertex shader source) */

// Build and compile the first shader
	int vertexShaderPurple = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShaderPurple, 1, &vertexShaderSource, NULL);
	glCompileShader(vertexShaderPurple);
	//check for compile errors
	int success;
	char infoLog[512];
	glGetShaderiv(vertexShaderPurple, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(vertexShaderPurple, 512, NULL, infoLog);
		cout << "Error::SHADER::VERTEX::COMPLIATION_FAILED\n" << infoLog << endl;
	}

	// Build and compile the second shader
	int vertexShaderYellow = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShaderYellow, 1, &vertexShaderSource, NULL);
	glCompileShader(vertexShaderYellow);
	// Check for compile errors
	glGetShaderiv(vertexShaderYellow, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(vertexShaderYellow, 512, NULL, infoLog);
		cout << "ERROR::SHADER::VERTEX::COMPLIATION_FAILED\n" << infoLog << endl;
	}

	// Build the THIRD shader
	int vertexShaderTri = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShaderTri, 1, &vertexShaderSource, NULL);
	glCompileShader(vertexShaderTri);
	glGetShaderiv(vertexShaderTri, GL_COMPILE_STATUS, &success);
	// Check for errors THIRD shader
	if (!success)
	{
		glGetShaderInfoLog(vertexShaderTri, 512, NULL, infoLog);
		cout << "ERROR::SHADER::VERTEX::COMPLIATION_FAILED\n" << infoLog << endl;
	}


	//Build the First fragment shader
	int fragmentShaderPurple = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShaderPurple, 1, &fragmentShaderSourcePurple, NULL);
	glCompileShader(fragmentShaderPurple);
	//check for fragment compile errors
	glGetShaderiv(fragmentShaderPurple, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(fragmentShaderPurple, 512, NULL, infoLog);
		cout << "ERROR::SHADER::FRAGMENT::COMPLIATION_FAILED\n" << infoLog << endl;
	}

	/* Build the second fragmant shader
	int fragmentShaderYellow = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShaderYellow, 1, &fragmentShaderSourceYellow, NULL);
	glCompileShader(fragmentShaderYellow);
	// Check for fragment compile errors
	glGetShaderiv(fragmentShaderYellow, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(fragmentShaderYellow, 512, NULL, infoLog);
		cout << "ERROR::SHADER::FRAGMENT::COMPLIATION_FAILED\n" << infoLog << endl;
	} */

	// Build the THIRD fragment shader
	int fragmentShaderTri = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShaderTri, 1, &fragmentShaderSourceTri, NULL);
	glCompileShader(fragmentShaderTri);
	// Check for errors on THIRD fragment shader
	glGetShaderiv(fragmentShaderTri, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(fragmentShaderTri, 512, NULL, infoLog);
		cout << "ERROR::SHADER::FRAGMENT::COMPLIATION_FAILED\n" << infoLog << endl;
	}


	//Linking the FIRST shader into a program
	int shaderProgramPurple = glCreateProgram();
	glAttachShader(shaderProgramPurple, vertexShaderPurple);
	glAttachShader(shaderProgramPurple, fragmentShaderPurple);
	glLinkProgram(shaderProgramPurple);
	// Check for linking errors
	glGetProgramiv(shaderProgramPurple, GL_LINK_STATUS, &success);
	if (!success)
	{
		glGetProgramInfoLog(shaderProgramPurple, 512, NULL, infoLog);
		cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << endl;
	}

	/* Link the SECOND shader into a new program
	int shaderProgramYellow = glCreateProgram();
	glAttachShader(shaderProgramYellow, vertexShaderYellow);
	glAttachShader(shaderProgramYellow, fragmentShaderYellow);
	glLinkProgram(shaderProgramYellow);
	// Check for linking errors
	glGetProgramiv(shaderProgramYellow, GL_LINK_STATUS, &success);
	if (!success)
	{
		glGetProgramInfoLog(shaderProgramYellow, 512, NULL, infoLog);
		cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << endl;
	} */

	// Link the THIRD shader into a new program
	int shaderProgramTri = glCreateProgram();
	glAttachShader(shaderProgramTri, vertexShaderTri);
	glAttachShader(shaderProgramTri, fragmentShaderTri);
	glLinkProgram(shaderProgramTri);
	// Check for linking errors
	glGetProgramiv(shaderProgramTri, GL_LINK_STATUS, &success);
	if (!success)
	{
		glGetProgramInfoLog(shaderProgramTri, 512, NULL, infoLog);
		cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << endl;
	}

	// Delete the FIRST shader objects
	glDeleteShader(vertexShaderPurple);
	glDeleteShader(fragmentShaderPurple);
	/* Delete the SECOND shader objects
	glDeleteShader(vertexShaderYellow);
	glDeleteShader(fragmentShaderYellow); */
	// Delete the THIRD shader objects
	glDeleteShader(vertexShaderTri);
	glDeleteShader(fragmentShaderTri);
